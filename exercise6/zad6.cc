/*
 ============================================================================
 Name        : Implementacja planisty cyklicznego
 Author      : Artur Trzop 13K3
 Version     : 1.0.0
 Copyright   : MIT
 Description : Zadanie 3 z laborki 6. C/C++, Ansi-style

 https://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/timery-i-zdarzenia
 ============================================================================
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h> // zawiera pause i sleep
#include <stdlib.h>
#include <string.h>
#include <time.h> // srand
#include <pthread.h>
#include <queue>
#include <process.h>
#include <unistd.h>
#include <sstream>

using namespace std;

// licznik zakończonych procesów
int counter_completedprocesses = 0;

// kolejka procesów oczekujących na przydział czasu procesora
queue<int> fifo_queue;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
	char name[50]; // nazwa procesu
	int delay; // opoznienie procesu
    int frequency; // częstotliwość
} structprocess;

structprocess structprocess_arr[50]; // tablica struktur

int global_pid = 0;

// zarządzanie procesem
void manage_process(sigval sigvalue)
{
	// blokujemy mutex
    pthread_mutex_lock(&mutex);

    int status;

    if(global_pid)
    {
    	// wysyłamy sygnał wstrzymania procesu
        kill(global_pid, SIGTSTP);

        // dodajemy na koniec kolejki pid
        fifo_queue.push(global_pid);

        cout<<"Process stopped PID="<<global_pid<<endl;
        cout.flush();
    }

    int i = (int)sigvalue.sival_ptr;

    global_pid = spawnl(P_NOWAIT, structprocess_arr[i].name, structprocess_arr[i].name, NULL);

    cout<<"Process started PID="<<global_pid<<endl;
    cout.flush();

    // odblokowujemy mutex po wyjsciu z sekcji krytycznej
    pthread_mutex_unlock(&mutex);


    while(waitpid(global_pid, &status, WEXITED) != -1)
    {
    	// początek sekcji krytycznej
        pthread_mutex_lock(&mutex);

        cout<<"Process finished PID="<<global_pid<<endl;
        cout.flush();

        global_pid = 0;
        counter_completedprocesses++;

        // sprawdzamy ilosc elementow w kolejce
        if(fifo_queue.size() > 0)
        {
        	// front() zwraca referencje do najstarszego elementu w kolejce
            global_pid = fifo_queue.front();

            // wysyłamy sygnał kontynuowania
            kill(global_pid, SIGCONT);

            cout<<"Process resumption PID="<<global_pid<<endl;
            cout.flush();

            // usuwamy najstarszy element w kolejce
            fifo_queue.pop();
        }

        // koniec sekcji krytycznej
        pthread_mutex_unlock(&mutex);
    }
}

void set_timer(int i)
{
	timer_t timer;

	// struktura opisująca zdarzenie
	// http://www.qnx.com/developers/docs/6.3.0SP3/neutrino/lib_ref/s/sigevent.html
    struct sigevent event;

    // struktura przechowująca informacje na temat upływu sekund od początku ery unixa oraz informacje o upływie milisekund od ostatniej sekundy.
    // http://www.qnx.com/developers/docs/6.3.0SP3/neutrino/lib_ref/t/timespec.html
    struct itimerspec itime;

    SIGEV_THREAD_INIT(&event, manage_process, i, NULL);

    // utworzenie timera
    timer_create(CLOCK_REALTIME, &event, &timer);

    itime.it_value.tv_sec = structprocess_arr[i].delay; // ustawiamy opóźnienie w sekundach
    itime.it_value.tv_nsec = 0; // opóźnienie z dokładnością do nanosekund

    itime.it_interval.tv_sec = structprocess_arr[i].frequency; // częstotliwość w sekundach
    itime.it_interval.tv_nsec = 0; // częstotliwość z dokładnością do nanosekund

    // możemy nastawić timer
    // http://www.qnx.com/developers/docs/6.3.0SP3/neutrino/lib_ref/t/timer_settime.html
    timer_settime(timer, 0, &itime, NULL);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	int limit = 5;
	const char* str; // przechowuje nazwe procesu który ma być uruchomiony jako zadanie zarządzane przez planiste


	cout<<"# Implementacja planisty cyklicznego - Artur Trzop 13K3\n\n";
	cout.flush();

	for(int i=0; i<limit; i++)
	{
		sleep(1); // opóźnienie 1 sekunda przed generowaniem nowego procesu

		/*
		ostringstream ss;
		ss << i;
		string s1 = "process_"+ss.str(); // nazwa procesu który ma być uruchomiony
		str = s1.c_str();
		*/

		// dla naszego przykładu wykorzystamy jeden proces który będzie wykonywał zadanie przez sekundę
		str = "zad6_exampleprocess";


		strncpy(structprocess_arr[i].name, str, sizeof(structprocess_arr[i].name));
		structprocess_arr[i].delay = rand()%(3*limit) + 1;
		structprocess_arr[i].frequency = rand()%limit + 5;


		cout<<"Proces info:\nNazwa: "<<structprocess_arr[i].name<<"\nDelay: "<<structprocess_arr[i].delay<<"\nFrequency: "<<structprocess_arr[i].frequency<<"\n\n";
		cout.flush();

		set_timer(i);
	}

	cout<<"> Dzialanie programu:"<<endl;
	cout.flush();

	// podtrzymanie zycia procesu
	while(true){}

	return EXIT_SUCCESS;
}

/*
//
// Przykładowy output:
//

# Implementacja planisty cyklicznego - Artur Trzop 13K3

Proces info:
Nazwa: zad6_exampleprocess
Delay: 14
Frequency: 8

Proces info:
Nazwa: zad6_exampleprocess
Delay: 7
Frequency: 8

Proces info:
Nazwa: zad6_exampleprocess
Delay: 6
Frequency: 5

Proces info:
Nazwa: zad6_exampleprocess
Delay: 12
Frequency: 6

Proces info:
Nazwa: zad6_exampleprocess
Delay: 15
Frequency: 8

> Dzialanie programu:
Process started PID=2659343
Process stopped PID=2659343
Process started PID=2659439
	Process running... My PID=2659439
	Process end... My PID=2659439
Process finished PID=2659439
Process resumption PID=2659343
	Process running... My PID=2659343
	Process end... My PID=2659343
Process finished PID=2659343
Process started PID=2667535
	Process running... My PID=2667535
Process stopped PID=2667535
Process started PID=2667631
	Process running... My PID=2667631
	Process end... My PID=2667631
Process finished PID=2667631
Process resumption PID=2667535
	Process end... My PID=2667535
Process stopped PID=2667535
Process started PID=2671727
Process finished PID=2671727
Process resumption PID=2667535
	Process running... My PID=2671727
Process stopped PID=2667535
Process started PID=2675727
	Process running... My PID=2675727
	Process end... My PID=2671727
Process finished PID=2675727
Process resumption PID=2667535
	Process end... My PID=2675727
Process finished PID=2667535
Process started PID=2683919
	Process running... My PID=2683919
	Process end... My PID=2683919
Process stopped PID=2683919
Process started PID=2684015
Process finished PID=2684015
Process resumption PID=2683919
	Process running... My PID=2684015
	Process end... My PID=2684015
Process finished PID=2683919
Process started PID=2692111
	Process running... My PID=2692111
Process stopped PID=2692111
Process started PID=2692207
	Process running... My PID=2692207
	Process end... My PID=2692207
Process stopped PID=2692207
Process started PID=2692208
Process finished PID=2692208
Process resumption PID=2692111
	Process end... My PID=2692111
Process finished PID=2692111
Process resumption PID=2692207
	Process running... My PID=2692208
Process stopped PID=2692207
Process started PID=2700303
	Process running... My PID=2700303
	Process end... My PID=2692208
Process finished PID=2700303
Process resumption PID=2692207
	Process end... My PID=2700303
Process finished PID=2692207
Process started PID=2708495
Process stopped PID=2708495
Process started PID=2708591
	Process running... My PID=2708591
Process stopped PID=2708591
Process started PID=2708592
	Process running... My PID=2708592
	Process end... My PID=2708592
Process finished PID=2708592
Process resumption PID=2708495
	Process running... My PID=2708495
Process stopped PID=2708495
Process started PID=2712688
	Process running... My PID=2712688
	Process end... My PID=2712688
Process finished PID=2712688
Process resumption PID=2708591
	Process end... My PID=2708591
Process finished PID=2708591
Process resumption PID=2708495
	Process end... My PID=2708495
Process finished PID=2708495
Process started PID=2724879
	Process running... My PID=2724879
Process stopped PID=2724879
Process started PID=2724975
	Process running... My PID=2724975
Process stopped PID=2724975
Process started PID=2724976
	Process running... My PID=2724976
	Process end... My PID=2724976
Process finished PID=2724976
Process resumption PID=2724879
	Process end... My PID=2724879
Process finished PID=2724879
Process resumption PID=2724975
	Process end... My PID=2724975
Process finished PID=2724975
Process started PID=2737167
	Process running... My PID=2737167
	Process end... My PID=2737167
Process finished PID=2737167
Process started PID=2741263
	Process running... My PID=2741263
Process stopped PID=2741263
Process started PID=2741359
	Process running... My PID=2741359
Process stopped PID=2741359
Process started PID=2741360
	Process running... My PID=2741360
Process stopped PID=2741360
Process started PID=2741361
	Process running... My PID=2741361
	Process end... My PID=2741361
Process finished PID=2741361
Process resumption PID=2741263
	Process end... My PID=2741263
Process finished PID=2741263
Process resumption PID=2741359
	Process end... My PID=2741359
Process finished PID=2741359
Process resumption PID=2741360
	Process end... My PID=2741360
Process finished PID=2741360
Process started PID=2757647
	Process running... My PID=2757647
Process stopped PID=2757647
Process started PID=2757743
	Process running... My PID=2757743
	Process end... My PID=2757743
Process finished PID=2757743
Process resumption PID=2757647
	Process end... My PID=2757647
Process finished PID=2757647
Process started PID=2765839
	Process running... My PID=2765839
Process stopped PID=2765839
Process started PID=2765935
	Process running... My PID=2765935
	Process end... My PID=2765935
Process finished PID=2765935
Process resumption PID=2765839
	Process end... My PID=2765839
Process finished PID=2765839
Process started PID=2774031
Process stopped PID=2774031
Process started PID=2774127
	Process running... My PID=2774127
	Process end... My PID=2774127
Process finished PID=2774127
Process resumption PID=2774031
	Process running... My PID=2774031
	Process end... My PID=2774031
Process finished PID=2774031
Process started PID=2782223
Process stopped PID=2782223
Process started PID=2782319
	Process running... My PID=2782319
	Process end... My PID=2782319
Process finished PID=2782319
Process resumption PID=2782223
	Process running... My PID=2782223
Process stopped PID=2782223
Process started PID=2786415
	Process running... My PID=2786415
Process stopped PID=2786415
Process started PID=2786416
	Process running... My PID=2786416
	Process end... My PID=2786416
Process finished PID=2786416
Process resumption PID=2782223
	Process end... My PID=2782223
Process finished PID=2782223
Process resumption PID=2786415
	Process end... My PID=2786415
Process finished PID=2786415
Process started PID=2798607
	Process running... My PID=2798607
	Process end... My PID=2798607
Process stopped PID=2798607
Process started PID=2798703
Process finished PID=2798703
Process resumption PID=2798607
	Process running... My PID=2798703
Process stopped PID=2798607
Process started PID=2802703
	Process running... My PID=2802703
	Process end... My PID=2798703
Process finished PID=2802703
Process resumption PID=2798607
	Process end... My PID=2802703
Process stopped PID=2798607
Process started PID=2806895
Process finished PID=2806895
Process resumption PID=2798607
	Process running... My PID=2806895
	Process end... My PID=2806895
Process finished PID=2798607
Process started PID=2814991
	Process running... My PID=2814991
	Process end... My PID=2814991
Process stopped PID=2814991
Process started PID=2815087
Process finished PID=2815087
Process resumption PID=2814991
Process stopped PID=2814991
	Process running... My PID=2815087
Process started PID=2819087
	Process running... My PID=2819087
Process stopped PID=2819087
Process started PID=2819184
	Process running... My PID=2819184
	Process end... My PID=2815087
Process finished PID=2819184

*/

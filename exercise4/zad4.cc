/*
 ============================================================================
 Name        : Zadanie 7. Przesyłanie sygnałów pomiędzy procesami - ping-pong
 Author      : Artur Trzop 13K3
 Version     : 1.0.0
 Copyright   : MIT
 Description : Zadanie 7 z laborki 4. C/C++, Ansi-style

 http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/komunikacja-posix
 ============================================================================
 */

#include <cstdlib>
#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <unistd.h> // zawiera pause i sleep
#include <stdlib.h> // srand

using namespace std;

// licznik wszystkich odebranych sygnałów
int sigcnt = 0;

// funkcja obsługi sygnału otrzymanego przez proces macierzysty
void sighandler_ping(int signum) {
	sigcnt++;
	cout<<"Proces macierzysty otrzymał sygnal (pileczke)\n[nr odebranego sygnalu: "<<signum<<", ilosc wszystkich sygnalow: "<<sigcnt<<"]\n\n";
	cout.flush();
}

// funkcja obsługi sygnału otrzymanego przez proces potomny
void sighandler_pong(int signum) {
	sigcnt++;
	cout<<"\t\tProces potomny otrzymał sygnal (pileczke)\n\t\t[nr odebranego sygnalu: "<<signum<<", ilosc wszystkich sygnalow: "<<sigcnt<<"]\n\n";
	cout.flush();
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	int losowa_liczba;
	int pid; // przechowuje id potomka


	if ((pid=fork())==0) // instrukcje procesu potomnego
	{
		// SIGUSR1 - sygnal zdefiniowany przez uzytkownika
		// http://students.mimuw.edu.pl/SO/Linux/Temat01/temat0151.html
		signal(SIGUSR1, sighandler_pong);

		printf("Proces potomny PID: %d, jego matka ma PID: %d\n\n##################################\n\n", getpid(), getppid());

		int i=0; // nr kroku pętli
		do {
			// blokujemy proces potomny
			pause();

			losowa_liczba = rand()%3+1; // losujemy od 1 do 3
			sleep(losowa_liczba);

			cout<<"\t\t"<<i<<". Potomek: pong (odpowiedz po czasie: "<<losowa_liczba<<"s)\n\n";
			cout.flush();

			// wyslanie sygnalu SIGUSR1 do procesu macierzystego
			// SIGUSR1 - Zdefiniowany przez uzytkownika sygnal
			kill(getppid(), SIGUSR1);

			i++;
		} while(1);

	}
	else // instrukcje procesu macierzystego
	{
		// Proces macierzysty po otrzymaniu sygnalu SIGUSR1 wywoła funkcje sighandler_ping
		signal(SIGUSR1, sighandler_ping);

		printf("Proces macierzysty PID: %d\n",getpid());

		int i=0; // nr kroku petli
		do {
			losowa_liczba = rand()%3+1; // losujemy od 1 do 3
			sleep(losowa_liczba);

			cout<<i<<". Macierzysty: ping (odpowiedz po czasie: "<<losowa_liczba<<"s)\n\n";
			cout.flush();

			// wyslanie sygnalu SIGUSR1 do potomka
			// SIGUSR1 - Zdefiniowany przez uzytkownika sygnal
			kill(pid, SIGUSR1);

			// blokujemy proces macierzysty
			pause();
			i++;
		} while(1);
	}

	return EXIT_SUCCESS;
}

/*
//
// Przykładowy output:
//

Proces macierzysty PID: 671781
Proces potomny PID: 671792, jego matka ma PID: 671781

##################################

0. Macierzysty: ping (odpowiedz po czasie: 2s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 1]

		0. Potomek: pong (odpowiedz po czasie: 2s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 1]

1. Macierzysty: ping (odpowiedz po czasie: 3s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 2]

		1. Potomek: pong (odpowiedz po czasie: 3s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 2]

2. Macierzysty: ping (odpowiedz po czasie: 3s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 3]

		2. Potomek: pong (odpowiedz po czasie: 3s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 3]

3. Macierzysty: ping (odpowiedz po czasie: 2s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 4]

		3. Potomek: pong (odpowiedz po czasie: 2s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 4]

4. Macierzysty: ping (odpowiedz po czasie: 3s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 5]

		4. Potomek: pong (odpowiedz po czasie: 3s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 5]

5. Macierzysty: ping (odpowiedz po czasie: 1s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 6]

		5. Potomek: pong (odpowiedz po czasie: 1s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 6]

6. Macierzysty: ping (odpowiedz po czasie: 2s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 7]

		6. Potomek: pong (odpowiedz po czasie: 2s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 7]

7. Macierzysty: ping (odpowiedz po czasie: 2s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 8]

		7. Potomek: pong (odpowiedz po czasie: 2s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 8]

8. Macierzysty: ping (odpowiedz po czasie: 1s)

		Proces potomny otrzymał sygnal (pileczke)
		[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 9]

		8. Potomek: pong (odpowiedz po czasie: 1s)

Proces macierzysty otrzymał sygnal (pileczke)
[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 9]

*/

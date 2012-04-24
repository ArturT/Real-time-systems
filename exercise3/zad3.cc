/*
 ============================================================================
 Name        : zad3 (Problem czytelników i pisarzy)
 Author      : Artur Trzop 13K3
 Version     : 1.4.0
 Copyright   : MIT
 Description : Zadanie 4 z laborki 3. C/C++, Ansi-style

 http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/zarzadzanie-watkami
 http://www.qnx.com/developers/docs/6.3.2/neutrino/lib_ref/p/pthread_mutex_lock.html
 http://www.qnx.com/developers/docs/6.3.2/neutrino/lib_ref/p/pthread_cond_wait.html
 ============================================================================
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <unistd.h> // zawiera sleep()
#include <pthread.h>
#include <time.h>

using namespace std;

// mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// zmienne warunkowe
pthread_cond_t cond_czytelnik = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_pisarz = PTHREAD_COND_INITIALIZER;

// tablica z numerami TID wątków
#define NUM_THREADS 20
pthread_t tid[NUM_THREADS];

const int SLEEP = 0;

struct biblioteka_t
{
	// aktualna ilość czytelnikow i pisarzy w bibliotece
	int czytelnikow_w_bib;
	int pisarzy_w_bib;

	// maksymalna liczba miejsc w czytelni
	const static int PLACES = 5;
};

// tworzymy nową instancje struktury biblioteki
biblioteka_t bib = {0, 0};

int czekajacy_pisarze = 0;
int czekajacy_czytelnicy = 0;


// ============================================================================

void debug()
{
	//printf("\tDebug: C w bib: %d, P w bib: %d\n", bib.czytelnikow_w_bib, bib.pisarzy_w_bib);
}

void *pisarz(void *arg)
{
	//printf("Uruchomiono watek pisarza (watek %d)\n", pthread_self());
	//cout.flush();
	czekajacy_pisarze++;

	pthread_mutex_lock(&mutex);

	while(bib.czytelnikow_w_bib > 0 || bib.pisarzy_w_bib > 0)
		pthread_cond_wait(&cond_pisarz, &mutex);

	bib.pisarzy_w_bib++;
	czekajacy_pisarze--;
	printf("# P=IN Wchodzi pisarz (watek %d) (aktualna ilosc pisarzy w bibliotece: %d) #\n", pthread_self(), bib.pisarzy_w_bib);
	cout.flush();


	// Pisarz pisze tekst w sekcji krytycznej. Inne wątki nie mogą pracować ponieważ nałożony jest mutex
	printf("# P=IN Pisarz pisze tekst... (watek %d) (aktualna ilosc pisarzy w bibliotece: %d) #\n", pthread_self(), bib.pisarzy_w_bib);
	cout.flush();
//	int losowa_liczba = rand()%2+1;
//	sleep(losowa_liczba);
	sleep(SLEEP);

	printf("# P=OUT Wychodzi pisarz (watek %d) (aktualna ilosc pisarzy w bibliotece: %d) #\n", pthread_self(), bib.pisarzy_w_bib);
	cout.flush();
	bib.pisarzy_w_bib--;
	if(bib.pisarzy_w_bib==0)
	{
		if(czekajacy_czytelnicy > 0)
		{
			// jeżeleli pisarz wyszedł z biblioteki to dajemy sygnał czytelnikom, że mogą wejść
			pthread_cond_broadcast(&cond_czytelnik);
		}
		else
		{
			// jesli zostali sami pisarze to im tez dajemy sygnal aby mogli wejsc
			// _signal pozwalamy tylko jednemu pisarzowi na wejscie
			pthread_cond_signal(&cond_pisarz);
		}
	}
	debug();
	pthread_mutex_unlock(&mutex);

	return 0;
}

void *czytelnik(void *arg)
{
	//printf("Uruchomiono watek czytelnika (watek %d)\n", pthread_self());
	//cout.flush();
	czekajacy_czytelnicy++;

	pthread_mutex_lock(&mutex);

	while(bib.pisarzy_w_bib > 0 || bib.czytelnikow_w_bib >= bib.PLACES)
		pthread_cond_wait(&cond_czytelnik, &mutex);

	bib.czytelnikow_w_bib++;
	czekajacy_czytelnicy--;
	printf("@ C=IN  Wchodzi czytelnik (watek %d) (aktualna ilosc czytelnikow w bibliotece: %d) @\n", pthread_self(), bib.czytelnikow_w_bib);
	cout.flush();

	//pthread_cond_broadcast(&cond_czytelnik);
	pthread_mutex_unlock(&mutex);

	// kod czytelnika wykonuje się poza sekcją krytyczną ponieważ wielu czytelników może czytać jednocześnie w bibliotece
	printf("@ C=IN Czytelnik czyta... (watek %d) (aktualna ilosc czytelnikow w bibliotece: %d) @\n", pthread_self(), bib.czytelnikow_w_bib);
//	int losowa_liczba = rand()%3;
//	sleep(losowa_liczba);
	sleep(SLEEP);

	pthread_mutex_lock(&mutex);
	bib.czytelnikow_w_bib--;
	printf("@ C=OUT Wychodzi czytelnik (watek %d) (aktualna ilosc czytelnikow w bibliotece: %d) @\n", pthread_self(), bib.czytelnikow_w_bib);
	cout.flush();

	if(bib.czytelnikow_w_bib == 0)
	{
		if(czekajacy_pisarze > 0)
		{
			// jesli czytelnik wyszedl z biblioteki to dajemy sygnal pisarzom, że mogą wejść
			pthread_cond_signal(&cond_pisarz);
		}
		else
		{
			// jeżeli zostali tylko czytelnicy to im tez dajemy sygnal aby mogli wejsc
			// musi byc _broadcast zeby mogło być wpuszczanych kilku czytelnikow na raz
			pthread_cond_broadcast(&cond_czytelnik);
		}
	}

	debug();
	pthread_mutex_unlock(&mutex);

	return 0;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int losowa_liczba, i, status;

	//utworzenie wątków
	for(i=0; i<NUM_THREADS; i++)
	{
		losowa_liczba = rand()%3; // losujemy od 0 do 2

		if(losowa_liczba == 0) //losowa_liczba == 0 //i < NUM_THREADS/2
		{
			// tworzymy watek pisarza
			pthread_create(&tid[i],NULL,pisarz,(void *)(i+1));
		}
		else
		{
			// tworzymy watek czytelnika
			pthread_create(&tid[i],NULL,czytelnik,(void *)(i+1));
		}
	}

	//oczekiwanie na zakończenie wątków
	for(i=0; i<NUM_THREADS; i++)
	{
		pthread_join(tid[i],(void**)&status);
		//printf("wątek %d zakończony, kod powrotu %d\n", tid[i], status);
	}

	cout<<"\nKONIEC";

	return EXIT_SUCCESS;
}
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

/*
 *
 * Poniższy program to przykładowy proces który wykonuje obciążające zadanie.
 * Będzie on dostawał czas procesora w zależności od tego jak przydzieli mu go planista cykliczny.
 *
 * */

#include <cstdlib>
#include <iostream>
#include <unistd.h> // zawiera pause i sleep
#include <stdlib.h>
#include <time.h> // srand

using namespace std;

int main(int argc, char *argv[])
{
	cout<<"\tProcess running... ";
	printf("My PID=%d\n", getpid());
	cout.flush();

	srand(time(NULL));

	//sleep(rand()%5+5);
	sleep(1);

	cout<<"\tProcess end... ";
	printf("My PID=%d\n", getpid());
	cout.flush();

	return EXIT_SUCCESS;
}

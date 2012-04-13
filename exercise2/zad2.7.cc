/*
 ============================================================================
 Name        : zad2.7
 Author      : Artur Trzop 13K3
 Version     : 1.0.1
 Copyright   : MIT
 Description : zad2.7 in C/C++, Ansi-style
 ============================================================================
 */

#include <cstdlib>
#include <iostream>

#include <stdio.h>
#include <process.h> // zawiera spawnl()
#include <stdlib.h> // zawiera exit()
#include <string>
#include <sstream>

using namespace std;

// http://stackoverflow.com/q/9779659
int getNumericalInput()
{
    string input = "";
    int result;

    while (true)
    {
        getline(cin, input);

        stringstream sStr(input);
        if (sStr >> result)
            return result;

        cout << "Invalid Input. Try again: ";
    }
}

int main(int argc, char *argv[])
{
	// pomocnicze zmienne
	int pid, i, res, status, ile_procesow_utworzyc;

	// bufor pomocniczy do konwersji typów funkcją itoa
	char buf[10];

	// wskaźniki do przechowywania stringów przekazywanych do argv procesów potomnych
	// nr_id to numer utworzonego procesu potomnego zaczynając od zera
	char *nr_id;

	// Liczba kroków jakie wykonają procesy potomne. Ustalone na sztywno 3 kroki dla każdego procesu potomnego.
	char *liczba_krokow = (char *)"3";

	// pobieramy do tej zmiennej znak z klawiatury aby okreslić tryb tworzenia procesów potomnych
	int tryb;

	// przypisujemy do tej zmiennej tryb tworzenia nowego procesu ze stałych np. P_NOWAIT itd.
	int mode;


	cout<<"# Podaj w jakim trybie maja byc tworzone procesy potomne\n1-P_WAIT \n2-P_NOWAIT \n3-P_NOWAITO \n";
	cout<<"# Wpisz numer trybu: ";
	tryb = getNumericalInput();

	switch(tryb)
	{
	case 1:
		mode = P_WAIT; // przed utworzeniem nowego procesu potomnego czeka na zakonczenie poprzednio utworzonego
		break;
	case 2:
		mode = P_NOWAIT; // umozliwia tworzenie kilku procesow potomnych jednoczesnie
		break;
	case 3:
		mode = P_NOWAITO; // tworzy kilka procesow potomych jednoczesnie i kontynuje prace procesu macierzystego bez czekania na procesy potomne. Nie mozna uzyc wait()
		break;
	default:
		mode = P_NOWAIT;
		break;
	}

	cout<<"\n# Ile chcesz utworzyc procesow potomnych? Podaj liczbe: ";
	ile_procesow_utworzyc = getNumericalInput();


	for(i=0; i < ile_procesow_utworzyc; i++)
	{
		// konwersja int na string
		// nr_id to kolejny numer nieujemny potomka utworzonego przez proces macierzysty.
		nr_id = itoa(i,buf,10);

		res = spawnl(mode, "potomnyProces","potomnyProces", nr_id, liczba_krokow, NULL);
		if(res < 0)
		{
			perror("# Blad funkcji spawn.");
			exit(i);
	     }
	}

	while((pid=wait(&status)) != -1)
	{
		// WEXITSTATUS zwraca kod powrotu przekazany przez funkcję exit() z procesu potomnego
		printf("# Proces potomny %d zakonczony, status nr_id=%d.\n", pid, WEXITSTATUS(status));
	}

	cout<<"# Koniec procesu macierzystego.";

	return EXIT_SUCCESS;
}
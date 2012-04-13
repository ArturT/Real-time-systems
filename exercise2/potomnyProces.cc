/*
 ============================================================================
 Name        : potomnyProces
 Author      : Artur Trzop 13K3
 Version     : 1.0.1
 Copyright   : MIT
 Description : potomnyProces element do zad2.7. C/C++, Ansi-style
 ============================================================================
 */

#include <cstdlib>
#include <iostream>

#include <process.h>
#include <stdio.h>
#include <unistd.h> // zawiera sleep()

using namespace std;

int main(int argc, char *argv[])
{
	// argv[1] zawiera nr_id czyli numer utworzonego procesu potomnego.
	int nr_id = atoi(argv[1]);

	// argv[2] zawiera liczbe krokow czyli ile razy ma wykonac sie pętla wyswietlajaca tekst.
	int liczba_krokow = atoi(argv[2]);


	for(int i=1; i<=liczba_krokow; i++)
	{
		cout<<">>> Proces potomny nr_id: "<<nr_id<<" (PID: "<<getpid()<<"), krok petli: "<<i<<"/"<<liczba_krokow<<"\n";
		
		// czyscimy bufor aby tekst mogl byc drukowany przed odczekaniem 1s
		cout.flush(); 
		
		// czekamy 1s do następnego kroku
		sleep(1);
	}

	// zwraca nr_id procesu
	exit(nr_id);
}
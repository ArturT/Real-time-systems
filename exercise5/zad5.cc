/*
 ============================================================================
 Name        : Proces klienta i proces serwera realizujący przesyłanie plików
 Author      : Artur Trzop 13K3
 Version     : 1.0.0
 Copyright   : MIT
 Description : Zadanie 3 z laborki 5. C/C++, Ansi-style

 http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/komunikacja-miedzy-zdarzeniami---rozszerzenia-qnx
 ============================================================================
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

// Od klienta do serwera przesyłane są następujące rodzaje komunikatów
#define OPENR 1 // Otwarcie pliku do odczytu
#define OPENW 2 // Otwarcie pliku do zapisu
#define READ 3 // Odczyt fragmentu pliku
#define CLOSE 4 // Zamkniecie pliku
#define WRITE 5 // Zapis fragmentu pliku
#define ERROR_NF 6 // Zgloszenie bledu braku pliku
#define STOP 10 // Zatrzymanie serwera

// Format komunikatu przesyłanego pomiędzy klientem a serwerem jest następujący
#define SIZE 512 // 512 bajtów.
typedef struct  {
    int  typ;       // typ zlecenia
    int  ile;       // liczba bajtow
    int  fh;        // uchwyt pliku
    char buf[SIZE]; // bufor
} mms;


// funkcja do pobierania z wejscia liczby
int getNumericalInput()
{
	cin.clear();

    string input = "";
    int result;

    while (true)
    {
        getline(cin, input);

        stringstream sStr(input);
        if (sStr >> result)
            return result;

        cout<<"Podaj poprawna liczbe: ";
        cout.flush();
    }
}

// funkcja odpowiedzialna za realizacje zadan po stronie serwera
void processerwera(char *ustaw_nazwe_serwera)
{
   name_attach_t *nazwa_serwera;
   mms msgkomunikat;
   int fh;
   int rcvid = 0;
   bool condition = true;


   // rejestracja nazwy serwera w GNS
   if ((nazwa_serwera = name_attach(NULL, ustaw_nazwe_serwera, 0)) == NULL)
   {
       cout<<"Nie udalo sie zarejestrowac nazwy serwera w GNS.\n";
       cout.flush();
   }
   else
   {
	   cout<<"Uruchomiono serwer!\n";
	   cout.flush();

	   // realizacja obslugi wiadomosci po stronie serwera
	   while (condition)
	   {
		   // odbieranie wiadomosci
		   rcvid = MsgReceive(nazwa_serwera->chid, &msgkomunikat, sizeof(msgkomunikat), NULL);
		   if (rcvid == -1)
		   {
			   cout<<"Nie udalo sie odebrac wiadomosci\n";
			   cout.flush();
			   break;
		   }

		   switch(msgkomunikat.typ)
		   {
			   case OPENR:
			   {
				   printf("Otwarcie do odczytu pliku: %s \n", msgkomunikat.buf);
				   fh = open(msgkomunikat.buf, O_RDONLY);
				   if(fh < 0)
				   {
					   MsgError(rcvid, ERROR_NF);
				   }
				   msgkomunikat.fh = fh;
				   MsgReply(rcvid, EOK, &msgkomunikat, sizeof(msgkomunikat));
				   break;
			   }
			   case OPENW:
			   {
				   printf("Przesylanie na serwer pliku: %s\n", msgkomunikat.buf);
				   fh = creat(msgkomunikat.buf, S_IRUSR | S_IWUSR);
				   msgkomunikat.fh = fh;
				   MsgReply(rcvid, EOK, &msgkomunikat, sizeof(msgkomunikat));
				   break;
			   }
			   case READ:
			   {
					int res = read(msgkomunikat.fh, msgkomunikat.buf, SIZE-1);
					if(res < 0)
					{
						cout<<"Wystapil problem z odczytem pliku.";
						cout.flush();
					}
					else
					{
						msgkomunikat.ile = res;
						MsgReply(rcvid, EOK, &msgkomunikat, sizeof(msgkomunikat));
					}
					break;
			   }
			   case WRITE:
			   {
				   write(msgkomunikat.fh, msgkomunikat.buf,msgkomunikat.ile );
				   MsgReply(rcvid, EOK, NULL, 0);
				   break;
			   }
			   case CLOSE:
			   {
				   close(msgkomunikat.fh);
				   MsgReply(rcvid, EOK, NULL, 0);
				   break;
			   }
			   case STOP:
			   {
				   MsgReply(rcvid, EOK, NULL, 0);
				   condition = false;
				   break;
			   }
			   default:
				   break;
		   }
	   }

	   // wyrejestrowanie nazwy serwera po zakonczeniu jego pracy
	   name_detach(nazwa_serwera, 0);

	   cout<<"Serwer zakonczyl prace!\n";
	   cout.flush();
   }
}

// funkcja odpowiedzialna za realizacje zadan po stronie klienta
void klientserwera(char *nazwa_serwera)
{
	int tryb = 0; // pomocnicza zmienna
	int serwer_id;
    int wiadomosc_id;
    char nazwa_pliku[SIZE];
    mms msg; // wiadomosc typu struktura mms
    bool condition = true;

    if((serwer_id = name_open(nazwa_serwera, 0)) == -1)
    {
        cout<<"Nie udalo sie polaczyc z nazwa serwera!";
    }
    else
    {
		while(condition)
		{
			cout<<"\n0) Pobierz plik z serwera.\n";
			cout<<"1) Wyslij plik na serwer\n";
			cout<<"2) Wyjscie\n";
			cout<<"Wybierz numer: ";
			tryb = getNumericalInput();

			switch(tryb)
			{
				case 0:
					{
						cout<<"\nPodaj nazwe pliku ktory chcesz pobrac z serwera: ";
						cout.flush();
						scanf("%s", &nazwa_pliku);

						msg.typ = OPENR;
						strncpy(msg.buf, nazwa_pliku, sizeof(msg.buf));
						wiadomosc_id = MsgSend(serwer_id, &msg, sizeof(msg), &msg, sizeof(msg));

						if(wiadomosc_id == -1)
						{
							if(errno == ERROR_NF)
							{
								printf("Plik o nazwie: \"%s\" nie istnieje!\n", msg.buf);
							}
							continue;
						}

						// odebrano uchwyt
						msg.typ = READ;
						msg.ile = SIZE-1;
						string odp = "";

						while(msg.ile == SIZE-1)
						{
							memset(&msg.buf[0], 0, sizeof(msg.buf));
							wiadomosc_id = MsgSend(serwer_id, &msg, sizeof(msg), &msg, sizeof(msg));
							odp += string(msg.buf);
						}
						msg.typ = CLOSE;
						wiadomosc_id = MsgSend(serwer_id, &msg, sizeof(msg), NULL, 0);

						// odpowiedz w postaci tresci pliku pobranej z serwera
						printf("Plik %s: ", nazwa_pliku);
						cout<<"\n"<<odp<<"\n";
					}
					break;

				case 1:
					{
						cout<<"\nPodaj nazwe pliku ktoru chcesz wyslac na serwer: ";
						cout.flush();
						scanf("%s", &nazwa_pliku);

						msg.typ = OPENW;
						strncpy(msg.buf, nazwa_pliku, sizeof(msg.buf));
						wiadomosc_id = MsgSend(serwer_id, &msg, sizeof(msg), &msg, sizeof(msg));

						msg.typ = WRITE;
						int fh = open(nazwa_pliku, O_RDONLY);

						if(fh == -1)
						{
							printf("Pliku o nazwie: \"%s\" nie mozna otworzyc!\n", nazwa_pliku);
						}

						int tmpread = 0;
						do
						{
							memset(&msg.buf[0], 0, sizeof(msg.buf));
							tmpread = read(fh, msg.buf, sizeof(msg.buf));
							msg.ile = tmpread;
							wiadomosc_id = MsgSend(serwer_id, &msg, sizeof(msg), NULL, 0);
						} while(tmpread > 0);

						msg.typ = CLOSE;
						wiadomosc_id = MsgSend(serwer_id, &msg, sizeof(msg), NULL, 0);

						cout<<"\nZapisano plik na serwerze.\n";
						cout.flush();
					}
					break;

				case 2:
					// Wyjscie. Zamykamy polaczenie z serwerem a takze informujemy serwer aby zakonczyl prace.
					msg.typ = STOP;
					MsgSend(serwer_id, &msg, sizeof(msg), NULL, 0);
					name_close(serwer_id);
					condition = false; // zatrzymujemy petle
					break;

				default:
					break;
			}
		}

		cout<<"\nZakonczono prace klienta.";
		cout.flush();
    }
}

int main(int argc, char *argv[])
{
	int tryb;
	bool warunek = true;
	char nazwa_serwera[100];

	cout<<"# Serwer plikow - Artur Trzop 13K3\n";
	cout<<"0) Uruchom serwer\n";
	cout<<"1) Uruchom klienta\n";
	cout<<"Wybierz numer: ";

	while(warunek)
	{
		tryb = getNumericalInput();
		switch(tryb)
		{
			case 0:
				warunek = false;
				cout<<"\nPodaj nazwe dla tworzonego serwera: ";
				scanf("%s", &nazwa_serwera);

				//cout<<"Nazwa uruchamianego serwera: "<<nazwa_serwera;
				//cout.flush();

				processerwera(nazwa_serwera);
				break;
			case 1:
				warunek = false;
				cout<<"\nPodaj nazwe serwera z ktorym chcesz sie polaczyc jako klient: ";
				scanf("%s", &nazwa_serwera);

				klientserwera(nazwa_serwera);
				break;
			default:
				cout<<"Wybierz co uruchomic podajac 0 lub 1: ";
				break;
		}
	}

	return EXIT_SUCCESS;
}


/*
//
// Przykładowy output dla serwera:
//

# Serwer plikow - Artur Trzop 13K3
0) Uruchom serwer
1) Uruchom klienta
Wybierz numer: 0

Podaj nazwe dla tworzonego serwera: Serwer1
Uruchomiono serwer!
Otwarcie do odczytu pliku: plik1.txt
Przesylanie na serwer pliku: plik2.txt
Serwer zakonczyl prace!

*/


/*
//
// Przykładowy output dla klienta:
//

# Serwer plikow - Artur Trzop 13K3
0) Uruchom serwer
1) Uruchom klienta
Wybierz numer: 1

Podaj nazwe serwera z ktorym chcesz sie polaczyc jako klient: Serwer1

0) Pobierz plik z serwera.
1) Wyslij plik na serwer
2) Wyjscie
Wybierz numer: Podaj poprawna liczbe: 0

Podaj nazwe pliku ktory chcesz pobrac z serwera: plik1.txt
Plik plik1.txt:
Jakis tekst w pliku :)


0) Pobierz plik z serwera.
1) Wyslij plik na serwer
2) Wyjscie
Wybierz numer: Podaj poprawna liczbe: 1

Podaj nazwe pliku ktoru chcesz wyslac na serwer: plik2.txt

Zapisano plik na serwerze.

0) Pobierz plik z serwera.
1) Wyslij plik na serwer
2) Wyjscie
Wybierz numer: Podaj poprawna liczbe: 2

Zakonczono prace klienta.

*/

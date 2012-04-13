/*
 ============================================================================
 Name        : killingCopy.c
 Author      : Artur Trzop 13K3
 Version     : 1.0.1
 Copyright   : MIT
 Description : killingCopy in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void fcopy(FILE *f1, FILE *f2, int *rozmiar)
{
	char buffer[512];
	size_t n;
	int sum_rozmiar = 0;

	int i = 1; // licznik ile razy kopiowano do buffora
	while ((n = fread(buffer, sizeof(char), sizeof(buffer), f1)) > 0)
	{
		if (fwrite(buffer, sizeof(char), n, f2) != n)
		   printf("Nieudany zapis do pliku.\n");
		else
		{
			sum_rozmiar += n;
			printf("%i. Skopiowano %i/512 bajtów.\n", i++, n);
		}
	}

	*rozmiar = sum_rozmiar;
}

int main(int argc, char *argv[]) {
	printf("# killingCopy v.1.0.1 - 2012 (c) Artur Trzop\n");

	if(argv[1] == NULL)
	{
		printf("Nie podano pierwszego argumentu.\n");
	}
	else if(argv[2] == NULL)
	{
		printf("Nie podano drugiego argumentu.\n");
	}
	else
	{
		printf("Poprawnie podano oba argumenty dla nazw plików...\n");

		/*
		Utwórz bufor buf o długości 512 bajtów
		Otwórz plik file2
		Utwórz plik file2
		Czytaj 512 bajtów z file1 do bufora buf
		Zapisz liczbę rzeczywiście odczytanych bajtów z bufora buf do pliku file2
		Jeśli liczba przeczytanych bajtów jest równa 512 to wróć do punktu 4 ...
		w przeciwnym wypadku zamknij pliki i zakończ program.
		*/

		FILE *fp1;
		FILE *fp2;
		int rozmiar = 0;
		int flag = 1;

		if((fp1 = fopen(argv[1], "rb")) == 0)
		{
			printf("Nie mozna otworzyc: %s\n", argv[1]);
			flag = 0;
		}

		if ((fp2 = fopen(argv[2], "wb")) == 0)
		{
			printf("Nie mozna otworzyc: %s\n", argv[2]);
			flag = 0;
		}


		if(flag == 1)
		{
			fcopy(fp1, fp2, &rozmiar);

			printf("Rozmar pliku, który skopiowalismy: %i\n", rozmiar);
		}
	}

	printf("\n");
	return EXIT_SUCCESS;
}
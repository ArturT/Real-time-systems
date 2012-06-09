# QNX Realtime Operating System

Opis
----

Przyk≥ady programÛw napisanych na QNX. 

Zadania na podstawie [Lab RTS](http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts)


Konfiguracja úrodowiska pracy
-----------------------------

### Instrukcja konfiguracji QNX i IDE
http://www.qnx.com/developers/docs/6.4.1/momentics/quickstart/about.html

Po zarejestrowaniu siÍ na qxn.com naleøy wype≥niÊ formularz, øe jest siÍ studentem aby mÛc uzyskaÊ klucz, ktÛry nie ma terminu waønoúci.

http://www.qnx.com/products/evaluation/academic_faculty.html

Jeúli nie widzaÊ od razu formularza na ww. stronie to naleøy odczekaÊ maks do 1 dnia aø pojawi≥ siÍ stosowny formularz.


### Tutaj moøna pobraÊ .iso QNX:
http://www.qnx.com/download/feature.html?programid=21182

Nie zawiera QNX Momentics IDE!


### .EXE zawierajπce QNX Momentics IDE:
http://www.qnx.com/download/feature.html?programid=21180 [dla Windowsa]

Na Windows 7 x64 nie dzia≥a kompilacja programÛw. 

http://www.qnx.com/download/feature.html?programid=21179 [dla Linux]

Warto siÍ zapoznaÊ z http://www.qnx.com/developers/articles/inst_4225_6.html#Start jeúli ktoú uøywa Ubuntu x64.


### A tutaj moøna pobraÊ wszystkie obrazy/pliki:
http://www.qnx.com/download/group.html?programid=20905



# Opis programÛw

Exercise 1
---------

Program stworzony jako projekt `QNX C Project`.

* èrÛd≥o: [Lab 1. killingCopy](http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/podstawy-obslugi-systemu)


Exercise 2
----------

### Konfiguracja

* Oba programy zad2.7 i potomnyProces stworzone jako projekty `QNX C++ Project`.

* Konfigurujπc projekt naleøy ustawiÊ aby program zad2.7 oraz potomnyProces by≥y uploadowane do tego samego katalogu na QNX np. do /home/zad2.7/

* Naleøy w Run configuration w zak≥adce upload ustawiÊ aby pliki programu nie by≥y usuwane po wgraniu oraz aby nie nadawano im unikatowej nazwy.


### Przyk≥adowy output

	# Podaj w jakim trybie maja byc tworzone procesy potomne
	1-P_WAIT 
	2-P_NOWAIT 
	3-P_NOWAITO 
	# Wpisz numer trybu: 2

	# Ile chcesz utworzyc procesow potomnych? Podaj liczbe: 3
	>>> Proces potomny nr_id: 0 (PID: 749608), krok petli: 1/3
	>>> Proces potomny nr_id: 1 (PID: 749609), krok petli: 1/3
	>>> Proces potomny nr_id: 2 (PID: 749610), krok petli: 1/3
	>>> Proces potomny nr_id: 0 (PID: 749608), krok petli: 2/3
	>>> Proces potomny nr_id: 1 (PID: 749609), krok petli: 2/3
	>>> Proces potomny nr_id: 2 (PID: 749610), krok petli: 2/3
	>>> Proces potomny nr_id: 0 (PID: 749608), krok petli: 3/3
	>>> Proces potomny nr_id: 1 (PID: 749609), krok petli: 3/3
	>>> Proces potomny nr_id: 2 (PID: 749610), krok petli: 3/3
	# Proces potomny 749608 zakonczony, status nr_id=0.
	# Proces potomny 749609 zakonczony, status nr_id=1.
	# Proces potomny 749610 zakonczony, status nr_id=2.
	# Koniec procesu macierzystego.

* èrÛd≥o: [Lab 2. Zadanie 7.](http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/zarzadzanie-procesami)


Exercise 3
----------

### Konfiguracja

Stworzone jako projekt `QNX C++ Project`.


### Przyk≥adowy output

	# P=IN Wchodzi pisarz (watek 2) (aktualna ilosc pisarzy w bibliotece: 1) #
	# P=IN Pisarz pisze tekst... (watek 2) (aktualna ilosc pisarzy w bibliotece: 1) #
	# P=OUT Wychodzi pisarz (watek 2) (aktualna ilosc pisarzy w bibliotece: 1) #
	@ C=IN  Wchodzi czytelnik (watek 3) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=IN Czytelnik czyta... (watek 3) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=IN  Wchodzi czytelnik (watek 4) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=IN Czytelnik czyta... (watek 4) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=IN  Wchodzi czytelnik (watek 5) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=IN Czytelnik czyta... (watek 5) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=IN  Wchodzi czytelnik (watek 6) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=IN Czytelnik czyta... (watek 6) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=IN  Wchodzi czytelnik (watek 7) (aktualna ilosc czytelnikow w bibliotece: 5) @
	@ C=IN Czytelnik czyta... (watek 7) (aktualna ilosc czytelnikow w bibliotece: 5) @
	@ C=OUT Wychodzi czytelnik (watek 3) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=OUT Wychodzi czytelnik (watek 4) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=OUT Wychodzi czytelnik (watek 5) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=OUT Wychodzi czytelnik (watek 6) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=OUT Wychodzi czytelnik (watek 7) (aktualna ilosc czytelnikow w bibliotece: 0) @
	# P=IN Wchodzi pisarz (watek 17) (aktualna ilosc pisarzy w bibliotece: 1) #
	# P=IN Pisarz pisze tekst... (watek 17) (aktualna ilosc pisarzy w bibliotece: 1) #
	# P=OUT Wychodzi pisarz (watek 17) (aktualna ilosc pisarzy w bibliotece: 1) #
	@ C=IN  Wchodzi czytelnik (watek 8) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=IN Czytelnik czyta... (watek 8) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=IN  Wchodzi czytelnik (watek 9) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=IN Czytelnik czyta... (watek 9) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=IN  Wchodzi czytelnik (watek 10) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=IN Czytelnik czyta... (watek 10) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=IN  Wchodzi czytelnik (watek 11) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=IN Czytelnik czyta... (watek 11) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=IN  Wchodzi czytelnik (watek 12) (aktualna ilosc czytelnikow w bibliotece: 5) @
	@ C=IN Czytelnik czyta... (watek 12) (aktualna ilosc czytelnikow w bibliotece: 5) @
	@ C=OUT Wychodzi czytelnik (watek 8) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=OUT Wychodzi czytelnik (watek 9) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=OUT Wychodzi czytelnik (watek 10) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=OUT Wychodzi czytelnik (watek 11) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=OUT Wychodzi czytelnik (watek 12) (aktualna ilosc czytelnikow w bibliotece: 0) @
	# P=IN Wchodzi pisarz (watek 21) (aktualna ilosc pisarzy w bibliotece: 1) #
	# P=IN Pisarz pisze tekst... (watek 21) (aktualna ilosc pisarzy w bibliotece: 1) #
	# P=OUT Wychodzi pisarz (watek 21) (aktualna ilosc pisarzy w bibliotece: 1) #
	@ C=IN  Wchodzi czytelnik (watek 13) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=IN Czytelnik czyta... (watek 13) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=IN  Wchodzi czytelnik (watek 14) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=IN Czytelnik czyta... (watek 14) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=IN  Wchodzi czytelnik (watek 16) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=IN Czytelnik czyta... (watek 16) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=IN  Wchodzi czytelnik (watek 18) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=IN Czytelnik czyta... (watek 18) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=IN  Wchodzi czytelnik (watek 15) (aktualna ilosc czytelnikow w bibliotece: 5) @
	@ C=IN Czytelnik czyta... (watek 15) (aktualna ilosc czytelnikow w bibliotece: 5) @
	@ C=OUT Wychodzi czytelnik (watek 14) (aktualna ilosc czytelnikow w bibliotece: 4) @
	@ C=OUT Wychodzi czytelnik (watek 16) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=OUT Wychodzi czytelnik (watek 18) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=IN  Wchodzi czytelnik (watek 20) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=IN Czytelnik czyta... (watek 20) (aktualna ilosc czytelnikow w bibliotece: 3) @
	@ C=OUT Wychodzi czytelnik (watek 13) (aktualna ilosc czytelnikow w bibliotece: 2) @
	@ C=OUT Wychodzi czytelnik (watek 15) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=OUT Wychodzi czytelnik (watek 20) (aktualna ilosc czytelnikow w bibliotece: 0) @
	@ C=IN  Wchodzi czytelnik (watek 19) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=IN Czytelnik czyta... (watek 19) (aktualna ilosc czytelnikow w bibliotece: 1) @
	@ C=OUT Wychodzi czytelnik (watek 19) (aktualna ilosc czytelnikow w bibliotece: 0) @

	KONIEC

* èrÛd≥o: [Lab 3. Zadanie 4.](http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/zarzadzanie-watkami)


Exercise 4
----------

### Konfiguracja

Stworzone jako projekt `QNX C++ Project`.


### Przyk≥adowy output

	Proces macierzysty PID: 671781
	Proces potomny PID: 671792, jego matka ma PID: 671781

	##################################

	0. Macierzysty: ping (odpowiedz po czasie: 2s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 1]

			0. Potomek: pong (odpowiedz po czasie: 2s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 1]

	1. Macierzysty: ping (odpowiedz po czasie: 3s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 2]

			1. Potomek: pong (odpowiedz po czasie: 3s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 2]

	2. Macierzysty: ping (odpowiedz po czasie: 3s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 3]

			2. Potomek: pong (odpowiedz po czasie: 3s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 3]

	3. Macierzysty: ping (odpowiedz po czasie: 2s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 4]

			3. Potomek: pong (odpowiedz po czasie: 2s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 4]

	4. Macierzysty: ping (odpowiedz po czasie: 3s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 5]

			4. Potomek: pong (odpowiedz po czasie: 3s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 5]

	5. Macierzysty: ping (odpowiedz po czasie: 1s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 6]

			5. Potomek: pong (odpowiedz po czasie: 1s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 6]

	6. Macierzysty: ping (odpowiedz po czasie: 2s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 7]

			6. Potomek: pong (odpowiedz po czasie: 2s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 7]

	7. Macierzysty: ping (odpowiedz po czasie: 2s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 8]

			7. Potomek: pong (odpowiedz po czasie: 2s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 8]

	8. Macierzysty: ping (odpowiedz po czasie: 1s)

			Proces potomny otrzyma≥ sygnal (pileczke)
			[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 9]

			8. Potomek: pong (odpowiedz po czasie: 1s)

	Proces macierzysty otrzyma≥ sygnal (pileczke)
	[nr odebranego sygnalu: 16, ilosc wszystkich sygnalow: 9]

* èrÛd≥o: [Lab 4. Zadanie 7.](http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/komunikacja-posix)


Exercise 5
----------

### Konfiguracja

Stworzone jako projekt `QNX C++ Project`.


### Przyk≥adowy output

	/*
	//
	// Przyk≥adowy output dla serwera:
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
	// Przyk≥adowy output dla klienta:
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

* èrÛd≥o: [Lab 5. Zadanie 3.](https://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/komunikacja-miedzy-zdarzeniami---rozszerzenia-qnx)


Exercise 6
----------

### Konfiguracja

Stworzone jako projekt `QNX C++ Project`.


### Przyk≥adowy output

	/*
	//
	// Przyk≥adowy output:
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
	
* èrÛd≥o: [Lab 6. Zadanie 3.](https://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/timery-i-zdarzenia)

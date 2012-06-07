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

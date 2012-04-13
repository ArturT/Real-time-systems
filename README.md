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

# QNX Realtime Operating System

Opis
----

Przyk³ady programów napisanych na QNX. 
Zadania na podstawie [Lab RTS](http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts)

Konfiguracja œrodowiska pracy
-----------------------------

### Instrukcja konfiguracji QNX i IDE
http://www.qnx.com/developers/docs/6.4.1/momentics/quickstart/about.html

Po zarejestrowaniu siê na qxn.com nale¿y wype³niæ formularz, ¿e jest siê studentem aby móc uzyskaæ klucz, który nie ma terminu wa¿noœci.
http://www.qnx.com/products/evaluation/academic_faculty.html
Jeœli nie widzaæ od razu formularza na ww. stronie to nale¿y odczekaæ maks do 1 dnia a¿ pojawi³ siê stosowny formularz.

### Tutaj mo¿na pobraæ .iso QNX:
http://www.qnx.com/download/feature.html?programid=21182
Nie zawiera QNX Momentics IDE!

### .EXE zawieraj¹ce QNX Momentics IDE:
http://www.qnx.com/download/feature.html?programid=21180 [dla Windowsa]
Na Windows 7 x64 nie dzia³a kompilacja programów. 

http://www.qnx.com/download/feature.html?programid=21179 [dla Linux]
Warto siê zapoznaæ z http://www.qnx.com/developers/articles/inst_4225_6.html#Start jeœli ktoœ u¿ywa Ubuntu x64.


### A tutaj mo¿na pobraæ wszystkie obrazy/pliki:
http://www.qnx.com/download/group.html?programid=20905



# Opis programów

Exercise 1
---------

Program stworzony jako projekt `QNX C Project`.
[killingCopy](http://sites.google.com/site/zbislawtabor/dydaktyka/systemy-czasu-rzeczywistego/laboratoria-rts/podstawy-obslugi-systemu)


Exercise 2
----------

### Konfiguracja

* Oba programy zad2.7 i potomnyProces stworzone jako projekty `QNX C++ Project`.

* Konfiguruj¹c projekt nale¿y ustawiæ aby program zad2.7 oraz potomnyProces by³y uploadowane do tego samego katalogu na QNX np. do /home/zad2.7/

* Nale¿y w Run configuration w zak³adce upload ustawiæ aby pliki programu nie by³y usuwane po wgraniu oraz aby nie nadawano im unikatowej nazwy.


### Przyk³adowy output

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

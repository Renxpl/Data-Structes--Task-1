hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/BagliListe.o -c ./src/BagliListe.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Gezici.o -c ./src/Gezici.cpp
	g++ -I ./include/ -o ./lib/BagliBagliListe.o -c ./src/BagliBagliListe.cpp
	g++ -I ./include/ -o ./lib/ListeGezici.o -c ./src/ListeGezici.cpp
	g++ -I ./include/ -o ./bin/Test.exe ./lib/BagliListe.o ./lib/Dugum.o ./lib/Gezici.o ./lib/BagliBagliListe.o ./lib/ListeGezici.o  ./src/main.cpp

calistir:
	./bin/Test.exe
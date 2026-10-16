tp4:	tp4.o fifo.o pile.o matrices.o parcours.o
	g++ out/obj/tp4.o out/obj/fifo.o out/obj/pile.o out/obj/matrices.o out/obj/parcours.o -o out/bin/tp4

tp4.o:	tp4.cpp
	g++ -c tp4.cpp -o out/obj/tp4.o

parcours.o:	private/parcours.cpp
	g++ -c private/parcours.cpp -o out/obj/parcours.o

matrices.o:	private/matrices.cpp
	g++ -c private/matrices.cpp -o out/obj/matrices.o

fifo.o:	private/fifo.cpp
	g++ -c private/fifo.cpp -o out/obj/fifo.o

pile.o:	private/pile.cpp
	g++ -c private/pile.cpp -o out/obj/pile.o
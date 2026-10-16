tp5:	tp5.o fifo.o matrices.o parcours.o pile.o dijkstra.o
	g++ out/obj/tp5.o out/obj/fifo.o out/obj/matrices.o out/obj/parcours.o out/obj/pile.o out/obj/dijkstra.o -o out/bin/tp5

tp5.o:	tp5.cpp
	g++ -c tp5.cpp -o out/obj/tp5.o

fifo.o:	Private/fifo.cpp
	g++ -c Private/fifo.cpp -o out/obj/fifo.o

matrices.o:	Private/matrices.cpp
	g++ -c Private/matrices.cpp -o out/obj/matrices.o

parcours.o:	Private/parcours.cpp
	g++ -c Private/parcours.cpp -o out/obj/parcours.o

pile.o:	Private/pile.cpp
	g++ -c Private/pile.cpp -o out/obj/pile.o

dijkstra.o:	Private/dijkstra.cpp
	g++ -c Private/dijkstra.cpp -o out/obj/dijkstra.o
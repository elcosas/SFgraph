CFLAGS=-I./include
SFML=-lsfml-graphics -lsfml-window -lsfml-system

build: main.o csv-reader.o bargraph.o
	g++ -o sfgraph main.o csv-reader.o bargraph.o $(CFLAGS) $(SFML)

clean:
	rm *.o

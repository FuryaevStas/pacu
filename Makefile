OUTNAME		= accounter.o
CFLAGS		= -lncursesw -lpthread -Wall -std=c++11

all: accounter

accounter: core.o render.o list.o config.o menu.o
	g++ core.o render.o list.o config.o menu.o -o $(OUTNAME) $(CFLAGS)

core.o: core.cpp header.h render.h render.h
	g++ -c core.cpp -o core.o $(CFLAGS)

menu.o: menu.cpp menu.h header.h
	g++ -c menu.cpp -o menu.o $(CFLAGS)
	
render.o: render.cpp render.h header.h config.o list.o
	g++ -c render.cpp -o render.o $(CFLAGS)

list.o: list.cpp list.h header.h config.o
	g++ -c list.cpp -o list.o $(CFLAGS)

config.o: config.cpp config.h header.h
	g++ -c config.cpp -o config.o $(CFLAGS)

clean:
	rm -rf *.o *.cfg
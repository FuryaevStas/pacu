OUTNAME		= accounter.o
CFLAGS		= -lncursesw -lpthread -Wall

all: accounter

accounter: core.o render.o
	g++ core.o render.o -o $(OUTNAME) $(CFLAGS)

core.o: core.cpp header.h render.h
	g++ -c core.cpp -o core.o
	
render.o: render.cpp render.h header.h
	g++ -c render.cpp -o render.o

clean:
	rm -rf *.o
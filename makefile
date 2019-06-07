all: ejecuta clean

ejecuta: docente
	./docente

docente: main.o docente.o
	g++ main.o docente.o -o docente -lxlsxio_read 

main.o: main.cpp
	g++ -c main.cpp 

docente.o: docente.cpp docente.h
	g++ -c docente.cpp 

clean:
	rm *.o docente
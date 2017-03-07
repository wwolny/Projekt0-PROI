all: program

program: ProiProjekt0.o
	g++ -o program ProiProjekt0.o

ProiProjekt0.o: ProiProjekt0.cpp
	g++ -c ProiProjekt0.cpp

debug:
	g++ -g ProiProjekt0.cpp -o program

release:
	g++ ProiProjekt0.cpp -o program

clean:
	rm -rf *o program
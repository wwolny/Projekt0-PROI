all: program

program: ProiProjekt0.o
	g++ -o program ProiProjekt0.o

ProiProjekt0.o: ProiProjekt0.cpp
	g++ -c ProiProjekt0.cpp
clean:
	rm -rf *o program
all: lab52exe

lab52exe: main.o class.o
	g++ -Wall -g -o lab52exe main.o class.o
	
main.o: main.cpp
	g++ -Wall -g -c main.cpp
	
class.o: class.cpp
	g++ -Wall -g -c class.cpp
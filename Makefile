###
### @author - Adil Chaudhry <chaudhra@oregonstate.edu>
### @description - Makefile for Project 3 
###

CFLAGS = -std=c++11

Project3: main.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Menu.o
	g++ $(CFLAGS) main.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Menu.o -o Project3

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp
	
Character.o: Character.cpp Character.h
	g++ $(CFLAGS) -c Character.cpp
	
Barbarian.o: Barbarian.cpp Barbarian.h
	g++ $(CFLAGS) -c Barbarian.cpp
	
Vampire.o: Vampire.cpp Vampire.h
	g++ $(CFLAGS) -c Vampire.cpp
	
BlueMen.o: BlueMen.cpp BlueMen.h
	g++ $(CFLAGS) -c BlueMen.cpp
	
Medusa.o: Medusa.cpp Medusa.h
	g++ $(CFLAGS) -c Medusa.cpp
	
HarryPotter.o: HarryPotter.cpp HarryPotter.h
	g++ $(CFLAGS) -c HarryPotter.cpp
	
Menu.o: Menu.cpp Menu.h
	g++ $(CFLAGS) -c Menu.cpp
	
clean:
	rm *.o Project3
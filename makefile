#this is a comment
#David Wallace
#2-15-2018

all		:	Zoo

Zoo	:	Zoo.o Creature.o  
			g++ -o Zoo.exe Zoo.o  Creature.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
Zoo.o	:	Zoo.cpp
			g++ -I ./ -c Zoo.cpp
				
Creature.o		:	Creature.cpp
			g++ -I ./ -c Creature.cpp
						

clean	:	Zoo.exe
			del *.o 
			del Zoo.exe
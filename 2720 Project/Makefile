CCC = g++11
CCCFLAGS = -std=c++11 -Wall -I /home/lib2720/allegro5/include/
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives
OBJECTS = Main.o Display.o AllegroSimulator.o GameSimulator.o Object.o Hero.o

all : clean-all game execute

game : $(OBJECTS)
	$(CCC) -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : %.cc
	$(CCC) $(CCCFLAGS) -c $^

clean :
	rm -f *.o *~ *% *# .#*

clean-all : clean
	rm -f game

execute : 
	game
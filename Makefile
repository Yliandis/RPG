CC = g++
EXEC = RPG
FLAGS = -std=c++17 -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
S = src
O = obj
B = bin

all: $(O) $(B) $(O)/Main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/Main.o: $(O)/Game.o 
	$(CC) $(S)/Main.cpp -c -o $(O)/Main.o $(FLAGS)

$(O)/Game.o: $(O)/Window.o $(O)/StateManager.o
	$(CC) $(S)/Game.cpp -c -o $(O)/Game.o $(FLAGS)

$(O)/StateManager.o: $(O)/StateWorld.o
	$(CC) $(S)/StateManager.cpp -c -o $(O)/StateManager.o $(FLAGS)

$(O)/StateWorld.o: $(O)/EventManager.o
	$(CC) $(S)/StateWorld.cpp -c -o $(O)/StateWorld.o $(FLAGS)

$(O)/Window.o: $(O)/EventManager.o
	$(CC) $(S)/Window.cpp -c -o $(O)/Window.o $(FLAGS)

$(O)/EventManager.o:
	$(CC) $(S)/EventManager.cpp -c -o $(O)/EventManager.o $(FLAGS)

clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)

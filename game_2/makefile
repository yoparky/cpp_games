# Output executable name
OUTPUT = game

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(OUTPUT)

$(OUTPUT): main.o Game.o Player.o
	$(CXX) main.o Game.o Player.o -o $(OUTPUT) $(LDFLAGS)

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.cpp Game.h Player.o
	$(CXX) $(CXXFLAGS) -c Game.cpp

Player.o: Player.cpp Player.h Player.o
	$(CXX) $(CXXFLAGS) -c Player.cpp

clean:
	rm *.o $(OUTPUT)
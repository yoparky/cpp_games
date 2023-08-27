game: main.o
	g++ main.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o game
output: main.o cell.hpp
	g++ main.o -g -o output -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp cell.hpp
	g++ -c main.cpp
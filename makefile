make: compile
	./main
compile:
	g++ main.cpp ./helper/globals.cpp ./classes/Matrix.cpp ./classes/Network.cpp ./classes/Layer.cpp -o main
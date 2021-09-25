make: compile
	./main
compile:
	g++ main.cpp ./classes/Layer.cpp ./classes/Neuron.cpp -o main
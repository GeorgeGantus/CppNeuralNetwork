make: compile
	./main
compile:
	g++ main.cpp ./classes/Layer.cpp ./classes/Neuron.cpp ./classes/Network.cpp ./classes/NetworkBatchData.cpp ./helper/globals.cpp -o main
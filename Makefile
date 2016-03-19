all: compile leitura

compile: main.cpp NeuralNet.cpp Layer.cpp Neuron.cpp
	g++  -std=c++0x main.cpp NeuralNet.cpp Layer.cpp Neuron.cpp -o main

leitura: leitura.cpp
	g++ -Wall leitura.cpp -o leitura

clean:
	rm main.sh

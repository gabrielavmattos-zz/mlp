all: compile leitura

compile: main.cpp NeuralNet.cpp Layer.cpp Neuron.cpp
	g++  -std=c++0x main.cpp NeuralNet.cpp Layer.cpp Neuron.cpp -o main

leitura: nova_versao_leitura.cpp
	g++ -Wall nova_versao_leitura.cpp -o leitura

clean:
	rm main.sh

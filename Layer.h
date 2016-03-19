/*

File: NeuralNet.cpp
Author: Gabriela Mattos
Resume: Implementation of the  layer.  Neural network multi-layer perceptrons.

*/

#include <stdlib.h>
#include <iostream>
#include "Neuron.h"

using namespace std;

class Layer
{

	public:
		Neuron *neuron;
		int numberNeuron;
		

		Layer();
		~Layer();

		void setLayer(int, int, bool);
		int getNumberNeuron();
		Neuron getNeuron(int);
		void getOutputs();
		float getNeuronOfError(int);
		float getNeuronOfWeight(int, int);
		int getPositionGreaterValue();
		int getPositionOutput(float);

		void adaptValues(float, int);
		void presentsInput(float*, int, int);
		float calculatesV(int);
		void presentDesiredOutputs(float, int);
		void back(bool, bool, float, int);
		
		
};


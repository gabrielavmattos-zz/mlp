/*

File: Neuron.cpp
Author: Gabriela Mattos
Resume: Implementation of the neuron. Neurons are the nodes found in perceptrons.


*/

#include <cfloat> // DBL_MAX
#include <cmath> // std::nextafter
#include <random>
#include <iostream>


//razão de aprendizado
#define gain 0.1

using namespace std;


class Neuron
{

	public:
		float value;
		
		//os pesos são correspondente a próxima camada, logo a camada de saída por não ter sinapse com prox não tera vetores de pesos.
		int numberSynapses; //Remember that it is a neural net complety
		float *weight;

		float threshold;
		float error;
		
		float d;


		Neuron();
		~Neuron();


		void setValue(float);
		float getValue();
		float getWeight(int);
		void setD(float);
		float getD();
		float getError();
		float getThreshold();
		
		void initializesWeightThreshold(int);
		void adaptValue(float);
		void calculatesError(bool, float);
		void adjustWeight();


};

	
		

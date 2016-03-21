#include "Neuron.h"




Neuron::Neuron()
{
	this->numberSynapses = 0;
}

Neuron::~Neuron()
{	
	delete []weight;
}



/* Step 1 - The Back-Propagation Training Algorithm
"Set all weights and node offsets to small random values." 

Referências: http://bytes.com/topic/c/answers/223101-rand-between-0-1-a
*/


void Neuron::initializesWeightThreshold(int numberSynapses)
{	  

	const float start = -0.5;
	const float stop = 0.5;

	std::random_device rd;
	std::mt19937 gen(rd());

	this->numberSynapses = numberSynapses;
	weight = new float [numberSynapses];


	std::uniform_real_distribution<> dis(start, std::nextafter(stop, DBL_MAX));
	int i;

	for(i=0; i<numberSynapses; i++)
	{

		//distribuição uniforme
		//colocar randomico entre intervalo [-1,1]
		weight[i] = dis(gen);
		//cout << weight[i] << endl;
	} 
	threshold = dis(gen);	

	//cout << threshold << endl;

}

//float Neuron::uniformDistribution(float value)



void Neuron::setValue(float value)
{
	this->value = value;
} 

float Neuron::getValue()
{
	return (this->value);
}

void Neuron::setD(float d)
{
	this->d = d;
} 

float Neuron::getD()
{
	return (this->d);
}

float Neuron::getWeight(int i)
{
	return (this->weight[i]);
}

float Neuron::getError()
{
	return (this->error);
}

float Neuron::getThreshold()
{
	return (this->threshold);
}

void Neuron::calculatesError(bool isOutput, float sum)
{
	//cout << isOutput << " Erro antes: " << this->error << endl;
	if (isOutput)
	{
		this->error = value * (1 - value) * (d - value);
	}
	else
	{
		this->error = value * (1 - value) * sum;
	}

	//cout << "Erro depois: " << this->error << endl;
}

void Neuron::adjustWeight()
{
	int i;

	for (i=0; i<numberSynapses; i++)
	{
		cout << "Error " << getError() << endl;
		cout << "gain: " << gain << endl;
		cout << "Value: " << getValue() << endl;
		cout << "Peso [" << i << "] antes: " << this->weight[i] << endl;
		this->weight[i] += getError()*getValue() *gain;
		cout << "Peso [" << i << "] depois: " << this->weight[i] << endl;
	}
}

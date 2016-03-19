#include <fstream>
#include <iostream>
#include <cstdlib>
#include <random>
#include "NeuralNet.h"


#define num_linhas 11181
#define num_colunas 12

#define num_linhas_conv 10800
#define num_colunas_conv 12

using namespace std;

string label[num_linhas][num_colunas];

float *dataTrain;
float *dataTest;

void readData()
{
	//	cout << "." << endl;
	ifstream infile_data;
	infile_data.open("dadosFil.tsv", ios::binary);
	int i = 0, j = 0, k = 0;
	string aux;

	while (!infile_data.eof())
	{
		//cout << "." << endl;
		getline(infile_data, aux);

		i=0;
		j=0;

		int tamanho = aux.size();

		while (i<tamanho and j<num_colunas)
		{
			if(aux[i] == '\t' || aux[i] == '\n')
			{
				j++;
			}		
			else
			{		
				label[k][j] += aux[i];
			}
			i++;
		}		
		k++;
	}		

	infile_data.close();

}

void conversao(int &numRowsTrain, int &numRowsTest)
{

	int i, j, k=0, l=0;
	int cont = 0;

	for (i=0; i<num_linhas_conv;i++)
		if (atof(label[i][num_colunas_conv-1].c_str())==0)
			cont++;

	numRowsTrain = num_linhas_conv - cont;
	numRowsTest = cont;

	cout << numRowsTrain << endl;
	cout << numRowsTest << endl;

	
	dataTest = new float[numRowsTest*(num_colunas_conv-1)];
	dataTrain = new float[numRowsTrain*(num_colunas_conv-1)];
	
	int isNull = 0;	
	
	for(i=0; i<num_linhas_conv; i++)
	{


		if (atof(label[i][num_colunas_conv-1].c_str())==0)
		{
			//cout << "Test: " << endl;
			for(j=0; j<num_colunas_conv-1; j++)
			{
			
				dataTest[k+j] = atof(label[i][j].c_str());
				//cout << k+j << " : " <<  dataTest[k+j] << "\t" ;
		
			}		
			
			k+=j;			
		}
		else
		{	
			//cout << "Train: " << endl;
			for(j=0; j<num_colunas_conv-1; j++)
			{
			
				dataTrain[l+j] = atof(label[i][j].c_str());
				//cout << l+j << " : " << dataTrain[l+j] << "\t" ;		
			}		
			
			l+=j;			
		}

		//cout << endl;
	}	

	cout << "Valores: " << k+l << endl;
	cout << "Teste: " << numRowsTest << endl;
	cout << "Treinoz: " << numRowsTrain << endl;
}

void divisaoTeste()
{￼
Renata Cancian
20 de abril de 2014 · 
 
Com Fhany Magalhães.
Compartilhar
1110
1 compartilhamento
Comentários
￼
Renata Cancian Casamento niver Nego e Titi pq família é tudo
20 de abril de 2014 às 21:45

	int i, j;
	int max, min;

	//min = data[i][num_colunas-1];	
		
	//for (i=2; i<num_linhas; i++)
	//	for (j=0; j<num_colunas; j++)
	//		if((int(data[i][num_colunas-1])<min+1))
			//	cont++;



}

int main(int argc, char ** argv)
{

	int numberLayersHidden = atoi(argv[2]);
	int numberNeuronsHidden = atoi(argv[1]);
	int numRowsTrain, numRowsTest;
	NeuralNet mlp(numberLayersHidden+2);

	cout << argv[1] << endl;

	//dados para treinamento
//	readData(argv[1]);
	readData();
	conversao(numRowsTrain, numRowsTest);

	//Aqui eu tenho um vetor com os dados de teste e outro com dados de dados de train
	//numRows é o numero de linhas correto
	int numCols = num_colunas_conv - 1;

	//qual o número de neuronios da camada de saída?
	int numberNeuronsOutput = 10;
	mlp.training(numRowsTrain, numRowsTrain, num_colunas_conv-1, dataTrain, num_colunas_conv-1, numberNeuronsOutput, &numberNeuronsHidden);
	mlp.testing(dataTest, numRowsTest,  numberNeuronsOutput, num_colunas_conv-1);

	cout << "S U C E S S O" << endl;

	return(0);
}

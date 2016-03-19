#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

#define num_linhas 11181
#define num_colunas 12

#define num_linhas_conv 11180
#define num_colunas_conv 12

float *data;

using namespace std;

float maximo (int col, int cont)
{
	
	int i; 
	float max=0;

	for(i=col; i<cont; i+=num_colunas_conv)
		if(max < data[i])
			max = data[i];

	return max;
}

int main()
{

	// Arquivo de entrada
	ifstream infile_data;
	infile_data.open("dados.tsv", ios::binary);

	// Arquivo de Saída
	ofstream outfile_data;
	outfile_data.open("dadosFil.tsv", ios::binary);
	
	// Declaração das variaveis
	int i = 0, j = 0, k = 0, cont = 0;
	string aux;

	// Variavel para receber dados do arquivo
	string label[num_linhas][num_colunas];
	
	// Primeira parte: leitura dos dados do arquivo
	while (!infile_data.eof())
	{
		getline(infile_data, aux);

		i=0;
		j=0;

		int tamanho = aux.size();
		int pos = aux.find("#NULL!");
		//cout << pos << endl;
		if (pos == -1)
		{
			cont++;
			while (i<tamanho and j<num_colunas)
			{
				if(aux[i] == '\t' || aux[i] == '\n')
				{
					j++;
			//		cout << "Aqui:  " << label[k][j-1] << endl;
				}		
				else
				{		
					label[k][j] += aux[i];
				}
				i++;
			}
			k++;
		}	

	}		
	k=0;
	int linhas = cont;
	// Variavel que será usada para armazenar os dados usaveis
	data = new float[cont*num_colunas_conv];

	int num_total = cont*num_colunas_conv;

	// Segunda Parte: conversão pra float
	for(i=1; i<cont; i++)
	{
		for(j=1; j<=num_colunas; j++)
		{
			//cout << i << " - " << j << " : "<< label[i][j] << endl;
			if ( j == num_colunas)
				data[k++] = 0;
			else
				data[k++] = atof(label[i][j].c_str());

			//cout << k-1 << " - " << num_total << ": " << data[k-1]<< endl;
			//cout <<  data[i][j] << "\t" ;		
		}		
		//cout << endl;
	}		


	for(i=0; i<100; i++)
	{		
		if(i%12==0 and i!=0)
			cout << endl;
		cout <<  data[i] << "\t" ;		
		
	}	
	

	int valor;
	i=0;
	int inicio, fim;
	//  Terceira parte: divisão dos casos que serão para teste e para treinamento
	while(i<num_total)
	{
		cont = 0;
		
		valor = data[i+num_colunas_conv-2];
		j = i+num_colunas_conv-2;
		while ((valor + 1) > data[j] and j < num_total)
		{
			cont++;
		//	cout << " Data [" <<j <<"] " << data[j] << endl;
			j+=num_colunas_conv;
			cout << " Data [" <<j <<"] " << data[j] << endl;
		}
		if (cont == 1)
			cont++;


		cout << "cont; " << cont << endl;
		j = cont/2;

		cout << "j " << j << endl;
		inicio = i+num_colunas_conv - 1;
		cout << "inicio : " << inicio << " - fim " << inicio+j*num_colunas_conv << endl;
		for(k = inicio; k<inicio+j*num_colunas_conv; k+=num_colunas_conv)
		{
			data[k] = 1;
			cout << "T: " <<  data[k-1] << endl;
		}

		i = i + cont*num_colunas_conv;
		cout << i << " - " << num_total << endl;

		
	}
		

//*******************************FUNCIONANDO ATÉ AQUI***********************************************//
	
	float max;
	for (i=2; i<num_colunas_conv-1; i++)
	{
		max = maximo(i, num_total);
		for(j=i; j<num_total; j+=num_colunas_conv)
		{		
			cout << j << endl;

			data[j] = data[j] / max;

			if (data[j] > 1.0)
				cout <<"Aqui " << data[j] << endl;
		}			
	}



	for(i=0; i<num_total; i++)
	{		
		if(i%12==0 and i!=0)
			outfile_data << endl;
		outfile_data <<  data[i] << "\t" ;		
		
	}
	
	cout << "linhas = " << linhas << endl;
	
	infile_data.close();
	outfile_data.close();
	

	return(0);
	

}

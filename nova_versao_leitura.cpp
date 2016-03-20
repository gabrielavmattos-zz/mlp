#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#define num_linhas 6090
#define num_colunas 9

#define num_linhas_conv 6090
#define num_colunas_conv 11

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
		getline(infile_data, aux); //pego toda a linha separada por \t

		i=0;
		j=0;

		int tamanho = aux.size();
		int pos = aux.find("#NULL!");
		if (pos == -1)
		{
			cont++;
			while (i<tamanho and j<num_colunas)
			{
				if(aux[i] == '\t' || aux[i] == '\n')
				{
					j++;
				//	cout << "Aqui:  "  << endl;//<< label[k][j-1] << endl;
				}		
				else
				{		
					label[k][j] += aux[i];
				//	cout << label[k][j] << endl;
				}
				i++;
			}
			k++;
		}
		else
		{ 
		//cout << aux << endl;
		}
	

	}

	cout << cont << endl;

	//for(i=0; i<10; i++)
	//	for (j=0; j<10; j++)
	//		cout << i << " - " << j << " : "<< label[i][j] << endl;

		
	k=0;
	int linhas = cont;
	// Variavel que será usada para armazenar os dados usaveis
	data = new float[cont*num_colunas_conv];
	int num_total = cont*num_colunas_conv;

	// Segunda Parte: conversão pra float
	for(i=1; i<linhas; i++)
	{
		for(j=0; j<=num_colunas+1; j++)
		{
			//cout << i << " - " << j << " : "<< label[i][j] << endl;
			if ( j == num_colunas or j == (num_colunas+1))
				data[k++] = 0;
			else
			{
				data[k++] = atof(label[i][j].c_str());
				//cout << atof(label[i][j].c_str()) << "\t" ;		
			}
			//cout << k-1 << " - " << num_total << ": " << data[k-1]<< endl;
			//cout <<  k <<  endl ;		
		}		
		//cout << endl;
	}		


	int connt[9];
	int num = 0;

	for (i=0; i<9; i++)
		connt[i] = 0;
	for(i=8; i<num_total; i+=num_colunas_conv)
	{		
		if (data[i]<17)
		{
			data[i+1] = 0;
			data[i+2] = num;
			//connt[0]++;
			
		
		}
		else if (data[i]<21)
		{
			data[i+1] = 1;
			//cont[1]++;
		
		}
		else if (data[i]<25)
		{
			data[i+1] = 2;
			//cont[2]++;
		
		}
		else if (data[i]<28)
		{
			data[i+1] = 3;
			//cont[3]++;
		
		}
		else if (data[i]<31)
		{
			data[i+1] = 4;
			//cont[4]++;
		
		}
		else if (data[i]<34)
		{
			data[i+1] = 5;
			//cont[5]++;
		
		}
		else if (data[i]<38)
		{
			data[i+1] = 6;
			//cont[6]++;
		
		}
		else if (data[i]<42)
		{
			data[i+1] = 7;
			//cont[7]++;
		
		}

		else if (data[i]<48)
		{
			data[i+1] = 8;
			//cont[8]++;
		
		}
		else
		{
			data[i+1] = 9;
			
		}
	}

		
//0	602	>17
//1	596	[17, 21[
//2	682	[21, 25[
//3	610	[25, 28[
//4	573	[28, 31[
//5	576	[31, 34[
//6	664	[34, 38[
//7	573	[38, 42[


	for(i=0; i<num_total; i++)
	{		
		if(i%num_colunas_conv==0 and i!=0)
			cout << endl;
		cout <<  data[i] << "\t" ;		
		
	}	
	/*

	int valor;
	i=0;
	int inicio, fim;
	// Terceira parte: divisão em categorias

	

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

		
	}*/
		

//*******************************FUNCIONANDO ATÉ AQUI***********************************************//
	/*
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


	int num_total = k;

	for(i=0; i<num_total; i++)
	{		
		if(i%12==0 and i!=0)
			outfile_data << endl;
		outfile_data <<  data[i] << "\t" ;		
		
	}
	
	//cout << "linhas = " << linhas << endl;
	
	outfile_data.close();*/
	
	infile_data.close();

	return(0);
	

}

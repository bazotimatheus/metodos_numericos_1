/*
Programa feito por:

Matheus Bazoti Brito Delgado
Renato Maciel Félix

Questão número três da primeira avaliação de Métodos Numéricos I 2019.2. Encontrar o valor interpolado em x = 3.5 usado o polinomio de Lagrange.
*/

#include<stdio.h>

#define L 6

main()
{
	FILE *arq;

	arq = fopen("dadosq3.dat","r");

	//matriz com os dados
	float data[L][2];
	
	//função e auxiliares
	double f = 0.;
	double x = 3.5;
	double prod;
	
	int i;
	int j;
	
	//colocando os dados salvos no arquivo na matriz
	for(i = 0; i < L; i++)
	{
		fscanf(arq, "%f\t%f\n", &data[i][0], &data[i][1]);
	}

	//f(x)
	for(i = 0; i < L; i++)
	{		
		prod = 1.0;
		
		for(j = 0; j < L; j++)
		{
			if(j != i)
				prod *= ((x - data[j][0]) / (data[i][0]-data[j][0])); 
		}
		
		f += data[i][1]*prod;

	}
	
	printf("\n Pelo método dos polinômio de Lagrange achamos f(%.1f) = %.1f.\n\n", x, f);
	
	fclose(arq);
}

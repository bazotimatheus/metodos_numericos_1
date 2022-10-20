/*
Programa feito por:

Matheus Bazoti Brito Delgado
Renato Maciel Félix

Questão número dois da primeira avaliação de Métodos Numéricos I 2019.2. Calculo numérico da posição em uma barra de 3 metros, onde temos uma deflexão de 9mm. Foi utilizado o método da secante para encontrar a raíz.
*/

#include<stdio.h>
#include<math.h>

//Definindo as constantes usadas no problema
#define L 3.
#define E 70.e9
#define I 52.9e-6
#define wo 15e3
#define y 9e-3
#define pi acos(-1)

#define error 1e-4

//Função que resolveremos
double f(double x)
{	return(( ( (wo*L) / (3.*pow(pi,4.)*E*I) ) * ( 48.*pow(L,3.)*cos((pi*x)/(2.*L)) - 48.*pow(L,3.) + 3.*pow(pi,3.)*L*pow(x,2.)  - pow(pi,3.)*pow(x,3.)) ) - y );
}

//Função que retorna a deflexão
double fy(double x)
{	return( ( (wo*L) / (3.*pow(pi,4.)*E*I) ) * ( 48.*pow(L,3.)*cos((pi*x)/(2.*L)) - 48.*pow(L,3.) + 3.*pow(pi,3.)*L*pow(x,2.)  - pow(pi,3.)*pow(x,3.))  );
}

int main()
{	double x1, x2, xi;
	int cont=0;

	//Dando um chute incial dentro do intervalo onde queremos uma solução física para o nosso problema (0<L<3)
	x1=0.;
	x2=3.;
	
	//Iniciando a procura da raiz da função f pelo método da secante
	do
	{	xi= x2 - (f(x2)*(x1-x2))/(f(x1)-f(x2));
		
		if(fabs(f(xi))<error)
			break;
			
		cont++;
		x1=x2;
		x2=xi;		
	}while(fabs(f(xi))>error);

	printf("\nA posição de x onde a deflexão é y= 9 mm é x=%.4f m\n", xi);
	printf("\nTeste se x encontrado é raiz: %lf",f(xi));
	printf("\nTeste se a raiz nos dá o ponto y= 9 mm: %lf",fy(xi));
	printf("\nEncontramos está raíz em %d passos!\n",cont);
}

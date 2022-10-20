/*
Programa feito por:

Matheus Bazoti Brito Delgado
Renato Maciel Félix

Questão número quatro da primeira avaliação de Métodos Numéricos I 2019.2. Calculo numérico da derivada de uma função dada, através dos métodos de diferenças finitas progressiva, agressiva e central. Além de utilizar o método central com a extrapolação de Richardson. 
*/

#include<stdio.h>
#include<math.h>

//Temos para o item i) um hi=0.2 e para o item ii) um hii=0.1
#define hi 0.2
#define hii 0.1

//Função do problema 
double f(double x)
{	return ( exp(pow(x,2))/x );
}

//Derivada analítica da função
double df(double x)
{	return ( 2*exp(pow(x,2)) - f(x)/x);
}

//Diferença progressiva. 
double progressiva(double x, double e)
{
	double xj;
		
	xj = x + e;
	
	return (( f(xj) - f(x) ) / ( xj -x ));	
}

//Diferença agressiva
double agressiva(double x, double e)
{
	double xi;
	
	xi= x - e;
	
	return (( f(x) - f(xi) ) / ( x - xi ));
}

//Diferença central
double central(double x, double e)
{
	double xi, xj;
	
	xi = x - e;
	xj = x + e;
	
	return ( (f(xj) - f(xi)) / (xj - xi) );
}

//Extrapolação de Richardson com a diferença central
double richardson(double x, double e)
{
	return ( (1.0/3.0) * ( 4.0*central(x,e/2.) - central(x,e) ) );
}

int main()
{	//Ponto utilizado para calcular as derivadas e a derivada analitica
	double x = 1.2;
	double dr;
	
	//Derivadas e erros em cada método. dp/ep=progressiva, da/ea=agressiva, dc/ec=central, dr1,dr2/er1,er2=Richardson 
	double dp;	
	double da;
	double dc;
	
	double ep;
	double ea;
	double ec;
	
	double dr1;
	double dr2;
	
	double er1;
	double er2;
	
	//Valor analítico
	dr = df(x);
	
	printf("\n Ponto utilizado: %.2lf.", x);
	printf("\n Valor analítico da derivada: %.4lf. \n",dr);

	//Caso i)
	//Cálculo das derivadas em cada método
	dp = progressiva(x,hi);
	da = agressiva(x,hi);
	dc = central(x,hi);
	
	//Cálculo dos erros para cada método
	ep = fabs((dp - dr)/dr)*100;
	ea = fabs((da - dr)/dr)*100;
	ec = fabs((dc - dr)/dr)*100;
	
	printf("\n Caso i) com hi = 0.2 \n");
	printf("\n Método\t\tValor\tErro");
	printf("\n Progessiva \t%.4lf\t%.4lf \% \n Regressiva \t%.4lf\t%.4lf \% \n Central \t%.4lf\t%.4lf \% \n", dp, ep, da, ea, dc, ec);
	
	//Caso ii)
	//Cálculo das derivadas em cada método
	dp = progressiva(x,hii);
	da = agressiva(x,hii);
	dc = central(x,hii);
	
	//Cálculo dos erros para cada método
	ep = fabs((dp - dr)/dr)*100;
	ea = fabs((da - dr)/dr)*100;
	ec = fabs((dc - dr)/dr)*100;
	
	printf("\n Caso ii) com hi = 0.1 \n");
	printf("\n Método\t\tValor\tErro");
	printf("\n Progessiva \t%.4lf\t%.4lf \% \n Regressiva \t%.4lf\t%.4lf \% \n Central \t%.4lf\t%.4lf \% \n", dp, ep, da, ea, dc, ec);

	//Usando a extrapoação de Richardson
	dr1 = richardson(x,hi);
	dr2 = richardson(x,hii);
	
	//Calculando os erros para cada valor de h com o a extrapolação
	er1 = fabs((dr1 - dr) / dr) * 100.0;
	er2 = fabs((dr2 - dr) / dr) * 100.0;
	
	printf("\n Com a extrapolação de Richardson utilizando o ponto central: \n");
	printf("\n h\t\tValor\tErro");
	printf("\n hi = 0.2\t%.4lf\t%.4lf\%\n hii = 0.1\t%.4lf\t%.4lf\%\n", dr1, er1, dr2, er2);
}

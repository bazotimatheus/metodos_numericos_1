#include<stdio.h>
#include<math.h>

#define error e-6

FILE *arq2a, *arq3a, *arq4a, *arqmod;

//Variáveis globais
double x1 = 0.;
double x2 = 1.5;
double v = 3.;
double h = .1;


double f(double x, double y)
{
	return( -1.2*y + 7.*exp(-0.3*x) );
}

void rungekutta2a()
{
	arq2a = fopen("segunda.out","w");
	double x = x1;
	double y = v;
	double yeu;
	double k1, k2;
	do
	{
		fprintf(arq2a,"%lf\t%lf\n", x, y);
		k1 = f(x, y);
		k2 = f(x + h, y + k1*h);
		x += h;
		y += ( k1 + k2 )*h/2.;
	}while(x <= x2);
	fclose(arq2a);	
}

void rungekutta3a()
{
	arq3a = fopen("terceira.out","w");
	double x = x1;
	double y = v;
	double k1, k2, k3;
	do
	{
		fprintf(arq3a,"%lf\t%lf\n", x, y);
		k1 = f(x, y);
		k2 = f(x + h*.5, y + k1*h*.5);
		k3 = f(x + h, y - k1*h + 2.*k2*h);
		x += h;
		y += ( k1 + 4.*k2 + k3)*h/6.;
	}while(x <= x2);
	fclose(arq3a);
}

void rungekutta4a()
{
	arq4a = fopen("quarta.out","w");
	double x = x1;
	double y = v;
	double k1, k2, k3, k4;
	do
	{
		fprintf(arq3a,"%lf\t%lf\n", x, y);
		k1 = f(x, y);
		k2 = f(x + h*.5, y + k1*h*.5);
		k3 = f(x + h*.5, y + k2*h*.5);
		k4 = f(x + h, y + k3*h);
		x += h;
		y += ( k1 + 2.*k2 + 2.*k3 + k4)*h/6.;
	}while(x <= x2);
	fclose(arq4a);	
}

void eulermod()
{
	arqmod = fopen("mod.out","w");
	double x = x1;
	double y = v;
	double yeu;
	do
	{
		fprintf(arqmod,"%lf\t%lf\n", x, y);
		x += h;
		yeu = y + f(x,y)*h;
		y += (f(x-h,y) + f(x,yeu))*h/2.;
	}while(x <= x2);
	fclose(arqmod);
}

void main()
{
	rungekutta2a();
	rungekutta3a();
	rungekutta4a();
	eulermod();
}

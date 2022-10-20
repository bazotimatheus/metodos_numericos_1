/*
Programa feito por:

Matheus Bazoti Brito Delgado
Renato Maciel Félix

Questão número um da primeira avaliação de Métodos Numéricos I 2019.2. Achar as raízes de: x³ + 12x² - 100x - 6 = 0
*/

#include<stdio.h>
#include<math.h>

#define erro 1e-4
#define p 10*erro

double f(double x)
{
        return ( pow(x,3) + 12*pow(x,2) - 100*x - 6 );
}

double dx(double xi, double xj)
{
        return ( ( f(xj) - f(xi) ) / (xj - xi) );
}

double newton(double x)
{
        return ( x - ( f(x) / dx(x-p, x+p) ) );
}

int novaraiz(double r[3], double x)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(fabs(x - r[i]) < erro)
			return(0);
	}
	return(1);
}

unsigned int seed    = 829658345;
unsigned int R       = 975678457;
 

void main()
{
        double x = 3, raiz[3];
        int m;

        do{
                x += p;
        }while(fabs(dx(x-p,x+p)) < erro);

        printf("\n");

        for(m = 1; m <= 3; m++)
        {
                do{
                        x = newton(x);

                        if( novaraiz(raiz, x) == 0 )
				x = 0;                 
                }while(fabs(f(x)) > erro);

                raiz[m-1] = x;

                printf(" Raiz #%d: x = %lf f(x) = %lf\n", m, raiz[m-1], f(raiz[m-1]));

                x += R*seed;
        }
        printf("\n");
}



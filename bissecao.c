#include<stdio.h>
#include<math.h>

#define epsilon 1e-4

float fun(float x)
{
	return(8.0 - 4.5*(x - sin(x)));
}

void main()
{
	float xn, a, b;
	
	printf("\n Insira um intervalo:");
	printf("\n a: ");
	scanf("%f", &a);
	printf("\n b: ");
	scanf("%f", &b);
	
	xn = (a + b)/2.0;
	
	do
	{
		if((fun(a)*fun(xn)) > 0. && (fun(b)*fun(xn)) > 0.)
		{
			printf("\n O intervalo não possui raiz, entre com um novo intervalo.\n");
			break;
		}
		if(fun(a)*fun(xn) < 0.0)
		{
			b = xn;
			xn = (a + b)/2.0;
		}
		if(fun(b)*fun(xn) < 0.0)
		{
			a = xn;
			xn = (a + b)/2.0;
		}
		printf("\n Em %f a função vale %f.\n", xn, fun(xn));
	}while(fabs(fun(xn)) >= epsilon);
	
	printf("\n");
}

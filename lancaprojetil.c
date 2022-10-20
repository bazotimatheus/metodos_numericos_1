#include<stdio.h>
#include<math.h>

#define epsilon 1e-4
#define g 9.8
#define Vo 15.2
#define x 18.2
#define h 1.82
#define y 2.1

float fun(float theta)
{
	return(y - x*tan(theta) + pow(x,2)*g/(2.*pow(Vo,2)*pow(cos(theta),2)) - h);
}

float funy(float theta)
{
	return(x*tan(theta) - pow(x,2)*g/(2.*pow(Vo,2)*pow(cos(theta),2)) + h);
}


void main()
{
	FILE *fp;
	
	fp = fopen("lanc.dat", "w");
	
	int i;
	float fu;
	
	float theta = 0., a, b;

	for(i = 0; i <= 200000; i++)
	{
		fprintf(fp, " %f\t %f\n", theta, funy(theta));
		theta = theta + .01;
	}

	fclose(fp);
	
	printf("\n Insira um intervalo: ");
	printf("\n a: ");
	scanf("%f", &a);
	printf("\n b: ");
	scanf("%f", &b);
	
	theta = (a + b) / 2.;
	
	do
	{
		if((fun(a)*fun(theta)) > 0. && (fun(b)*fun(theta)) > 0.)
		{
			printf("\n O intervalo não possui raiz, entre com um novo intervalo.\n");
			break;
		}
		if(fun(a)*fun(theta) < 0.0)
		{
			b = theta;
			theta = (a + b)/2.0;
		}
		if(fun(b)*fun(theta) < 0.0)
		{
			a = theta;
			theta = (a + b)/2.0;
		}
		printf("\n Em %f rad a função vale %f.\n", theta, fun(theta));
	}while(fabs(fun(theta)) >= epsilon);
	
	printf("\n Conferindo o valor achado: y = %f.", funy(theta));	
	
	theta = theta * 180. / 3.14;
	
	printf("\n Em graus: %fº. \n\n", theta);
	
	printf("\n");
}

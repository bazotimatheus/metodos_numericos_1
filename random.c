#include<stdio.h>
#define MAXN 4294967295.

void main(void)
{
	FILE *arc;
	
	unsigned int 	seed, R;
	float 			rn, rm;
	int 			i;
	arc = fopen("random.dat", "w");
	
	seed 	= 829658345;
	R 		= 975078457;
	
	for(i = 1; i <= 100000; i++)
	{
		R = R * seed;
		rn = R / MAXN;
		
		R = R * seed;
		rm = R / MAXN;
		
		fprintf(arc, "%f\t%f\n", rn, rm);
	}
	fclose(arc);
}

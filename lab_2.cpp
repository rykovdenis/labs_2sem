#include<stdio.h>
#include<stdlib.h>
void check(int* p, int len)
{
	int i, j, k, a1[5];
	for (i = 0; i < len; i++)
	{
		for(j = 0;j < 5; j++)
		{
			a1[j] = *(p + i) % 10;
			*(p + i) = *(p + i) / 10;
		}
		if((a1[2] == a1[1] * a1[0]) && (a1[2] == a1[3] * a1[4]))
		{
			for (k = 4;k >= 0; k--)
			{
				printf("%d", a1[k]);
			}
			printf("\n");
		}
	}	
}


int main()
{
	int a[6] = {43211,11111,23616,33333,55555,10000}, len = sizeof(a) / sizeof(a[0]);
	int *p = &a[0]; 
	check(&a[0], len);
}

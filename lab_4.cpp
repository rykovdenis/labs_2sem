#include<stdio.h>
#include<math.h>

int maxim(int * p, int len, int * maxi, int * count)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		if(*(p + i)>*(maxi))
		{
			*maxi = *(p + i);
		}
		for(j = 2;j <= sqrt(*(p + i));j++)
		{

			if(*(p + i) % j == 0)
			{
				(*count)++;
				break;
			}
				
		}
	}
	return 0;
}

int main()
{
	int a[] = {54, 21, 1, 7, 2, 888, 655, 4533, 99}, len = sizeof(a)/sizeof(int),i;
	printf("massive:");
	for(i = 0; i< len;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	int *p, *p1, *p2;
	p = &a[0];	
	int maxi = a[0] , count = 0;
	int(*pfunc)(int*, int, int*, int *);
	pfunc = &maxim;	
	p1 = &maxi;
	p2 = &count;
	pfunc(p, len, p1, p2);
	printf("max = %d, number of simple nums is %d", maxi, count);
}

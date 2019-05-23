#include<stdio.h>
#include<stdlib.h>
int check(char a[], int n)
{
	int i, l, j, res = 0, count = 0, k2 = 0;
	double sr,k = 0.0;
	char glas[8] = {'i', 'u', 'y', 'o', 'e', 'a'};
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < 8; j++)
		{
			if(a[i] == glas[j])
			{
				k++;
			}
		}
	}
	sr = k / n * 5;
	printf("sr = %lf\n", sr);
	k = 0.0;
	for(i = 0; i < n / 5; i++)
	{
		for(j = 0; j < 5; j ++)
		{
			for(l = 0; l < 8; l++)
			{
				if(a[i * 5 + j] == glas[l])
				{
					k++;
				}
			}
		}
		printf("sr%d = %lf\n",i+1, k);
		if(k > sr)
		{
			res++;
			
		}
		k = 0.0;
		count++;
	}
	while (a[count * 5 + k2] != '\0')
	{
		for(l = 0; l < 8; l++)
		{
			if(a[count * 5 + k2] == glas[l])
			{
				k++;
			}						
		}
		printf("%c",a[count * 5 + k2] );
		k2++;
	}
	printf("\n%lf\n",k );
	if(k > sr)
	{
		res ++;
	}
	return res;
}
int main()
{
	int b;
	
	char str[9] = {'a','a','t','r','t','w','o','o','\0'};
	b = check(str,8);
	printf("%d",b);
}

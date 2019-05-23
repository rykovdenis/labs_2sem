#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* read_file(char* address, size_t* len)
{// Считывем массив из файла
	FILE* f_in;
	int* arr=0;
	f_in = fopen(address, "r"); //открыть файл, режим "r" - чтение
	if(f_in!=0) // или if(f_in) - файл удалось открыть
	{
		fscanf(f_in, "%d", len);
		size_t i=0;
		arr = (int*)calloc(*len, sizeof(int));
		while(i<*len)
		{
			fscanf(f_in, "%d", &arr[i]);
			i++;
		}
		fclose(f_in);
	}
	return arr;
}
int find_max(int * a)
{
	int max = *a, i;
	for(i = 1; i < 12;i++)
	{
		if(*(a + i) > max)
		{
			max = *(a + i);
		}
	}
	return max;	
}

int write_to_file(char* address, int* arr, size_t len)
{// Записываем отсортированный массив в файл
	FILE* f_out;
	f_out = fopen(address, "w"); 
	if(f_out!=0) 
	{
		fprintf(f_out, "%d", len);
		size_t i=0;
		while(i<len)
		{
			fprintf(f_out, " %d", arr[i]);
			i++;
		}
		fclose(f_out);
		return 1;
	}
	return 0;
}

int* copy_array(int* a, size_t len)
{// Копирование исходного массива
	int* arr = (int*)calloc(len, sizeof(int));
	size_t i=0;
	for(;i<len;i++)
	{
		arr[i] = a[i];
	}
	return arr;
}


void bubble_sort(int *a, int len)
{
	int i, j, k;
	for (i = 0; i < len; i++)
	{
		for (j = 0;j < len - i - 1; j++)
		{
			if(a[j]>a[j + 1])
			{
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] =k;	
			}
		}
	}
}

void radix_sort(int * a,int len)
{
	int i, k = 1,count = 0, max, j;
	max = find_max(a);
	printf("max =%d\n", max);	
	int b[12];
	while(max / k > 0)
	{		
		for (i = 0; i < 10; i++)
		{
			for(j = 0; j < len; j++)
			{
				if((*(a + j) / k) % 10 == i)
				{
					b[count] = *(a+j);
					count++;
				}				
			}
		}
		k *=10;
		count = 0;
		for(j = 0; j < len; j++)
		{
			*(a + j) = b[j];								
		}
	}
}

int main()
{
	char adress[] = "in.txt";
	char file_out_path[] = "out.txt";
	char file_out_path2[] = "out2.txt";
	int* arr;	
	size_t len;
	size_t i = 0;
	char c;
	arr = read_file(adress, &len);
	if(arr==0)
	{
		printf("\nCouldn't read file. Closing...");
		return 0;
	}
	printf("\nArray from file: \n");
	for(i=0;i < len; i++) 
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int* arr2 = copy_array(arr, len);
	radix_sort(arr,len);
	printf("\nSorted array using radix sort: \n");
	for(i = 0;i < len; i++)
	{
		printf("%d ", arr[i]);
	} 
	printf("\n");
	printf("\nWrite attempt: %d", write_to_file(file_out_path,arr, len));
	printf("\n");
	bubble_sort(arr2,len);
	printf("\nSorted array by bubble sort: \n");
	for(i=0;i<len;i++)
	{
		printf("%d ", arr2[i]);	
	} 
	printf("\n");
	printf("\nWrite attempt: %d", write_to_file(file_out_path2, arr2, len));
	printf("\n");
	if(arr!=0)
	{
		free(arr);
	}
	if(arr!=0)
	{
		free(arr);
	}
	if(arr2!=0)
	{
		free(arr2);
	}
		
	system("pause");
	return 0;
}

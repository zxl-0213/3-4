//合并2个有序数组
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

void print(int* num1, int size)
{
	int j = 0;
	while (j < size)
	{
		printf("%d", num1[j]);
		j++;
	}
}
void merge(int* num1, int num1Size, int n, int* num2, int num2Size, int m)
{
	int i1 = 0,i2 = 0;
	int i = 0;
	int* Array = (int*)malloc(sizeof(int) * (m + n));
	if (Array == NULL)
	{
		printf("申请失败");
		exit(-1);
	}
	while (i1 < n && i2 < m)
	{
		if (num1[i1] > num2[i2])
		{
			Array[i] = num2[i2];
			i++;
			i2++;
		}
		else
		{
			Array[i] = num1[i1];
			i++;
			i1++;
		}
	}
	while(i1 < n)
	{
		Array[i] = num1[i1];
		i1++;
		i++;

	}
	while (i2 < m)
	{
		Array[i] = num2[i2];
		i++;
		i2++;
	}
	memcpy(num1, Array, sizeof(int)*(m + n));
	

}

int main()
{
	int num1[6] = {0,2,3,0,0,0};
	int num2[3] = {3,4,6};
	merge(num1,sizeof(num1)/sizeof(num1[0]),3,num2,sizeof(num2)/sizeof(num2[0]),3);
	print(num1, sizeof(num1)/sizeof(num1[0]));
	return 0;
}
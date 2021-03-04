//旋转数组，将数组中的元素向右移动k个位置。
#include<stdio.h>
void reverse(int* num,int left,int right)
{
	while (left < right)

	{
		int temp = num[right];
		num[right] = num[left];
		num[left] = temp;
		left++;
		right--;
	}
}
void print(int* num, int size)
{
	int i = 0;
	while (i<size)
	{
		printf("%d",num[i]);
		i++;
	}
}
void rotate(int* num, int numSize, int k)
{
	k %= numSize;// 防止k的值大于numSize
	reverse(num,0,numSize-k-1);
	reverse(num,numSize-k,numSize-1);
	reverse(num,0,numSize-1);
	
}
int main()
{
	int k = 3;
	int num[] = {1,2,3,4,5,6,7};
	rotate(num,sizeof(num)/sizeof(num[0]),k);
	print(num, sizeof(num) / sizeof(num[0]));
	return 0;
}
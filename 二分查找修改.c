#include<stdio.h>
int Find_num(int* arr, int sz, int num)
{
	int m = 1;
	int left = 0;
	int right = sz - 1;
	while (m)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > num)
		{
			right = mid - 1;
		}
		else if (arr[mid] < num)
		{
			left = mid + 1;
		}
		else
			return mid + 1;  
	}
}
int main()
{
	int i;
	int j;
	int t;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("输入一个数字，将会得到他的位置\n");
	scanf("%d", &i);
	j = sizeof(arr) / sizeof(arr[0]);
	t = Find_num(arr,j,i);
	printf("这个数字的位置是第%d位\n", t);
	return 0;
}
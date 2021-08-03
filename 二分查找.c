#include<stdio.h>
int Find_num(int* arr, int sz, int num)
{
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		int mid = left + (right - left) / 2;//中位数
		if (arr[mid] < num)
			left = mid + 1;
		else if (arr[mid] > num)
			right = mid - 1;
		else
			return mid; 
	}
	return -1;
}
int main()
{
	int i, input, sz;
	int arr[10] = { 1,2,3,4,5,6,7,8,29,190 };
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("输入一个数字，将会得到他的位置\n");
	scanf("%d", &input);
	sz = sizeof(arr) / sizeof(arr[0]);
	i = Find_num(arr,sz,input);
	if (i != -1)
		printf("这个数字的位置是第%d位\n", i+1);
	else
		printf("输入数据错误\n");
	return 0;
}
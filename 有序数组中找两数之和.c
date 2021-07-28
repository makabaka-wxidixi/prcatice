#include<stdio.h>
#include<stdlib.h>
int* findnum(int arr[], int sz,int num)
{
	int left = 0;
	int right = sz - 1;
	int* m = (int*)malloc(sizeof(int) * 2);
	while (left < right)
	{
		if (arr[left] + arr[right] > num)
			right--;
		if (arr[left] + arr[right] < num)
			left++;
		else
			break;
	}
	if (left < right)
	{
		m[0] = left;
		m[1] = right;
		return m;
	}
	else
		return NULL;
}
int main()
{
	int arr[] = { 2,4,6,7,8,9 };
	int n = 14;//ÒªÕÒµÄÊý×Ö
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* ret = findnum(arr, sz, 14);
	if (ret != NULL)
	{
		printf("%d ", ret[0]);
		printf("%d ", ret[1]);
	}
	return 0;
}
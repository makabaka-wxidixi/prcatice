#include<stdio.h>

int minnum1(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < arr[right])
		{
			right = mid;
		}
		else if (arr[mid] > arr[right])
		{
			left = mid + 1;
		}
		else
		{
			right--;
		}
	}
	return arr[left];
}
int main()
{
	int arr1[] = { 5,6,7,8,9,2,3,4 };//ÉıĞòÓÒĞı
	int arr2[] = { 2,2,2,2,2,0,1,2,2,2 };//ÉıĞòÓÒĞı
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int ret1 = minnum1(arr1, sz1);
	int ret2 = minnum1(arr2, sz2);
	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);
	return 0;
}
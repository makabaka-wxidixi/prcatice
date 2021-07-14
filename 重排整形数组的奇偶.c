#include<stdio.h>
void exchange(int* arr,int sz)
{
	int* left = arr;
	int* right = arr + sz - 1;
	//int left = 0;
	//int right = sz - 1;
	int tmp = 0;
	while (left < right)
	{
		while (left < right)//×ó±ßÕÒÅ¼Êý
		{
			if (*left % 2 == 0)
				break;
			else
				left++;
		}
		while (left < right)//ÓÒ±ßÕÒÆæÊý 
		{
			if (*right % 2 == 1)
				break;
			else
				right--;
		}
		if (left < right)
		{
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
		
	}
}
int main()
{
	int i;
	int arr[] = { 1,3,5,7,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	exchange(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
#include<stdio.h>
void my_bubble_sort(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 20, 10, 1, 1, 8, 2, 9, 9, 2, 4, 4, 7, 6, 6, 12, 12, 10 };
	int sz = sizeof(arr) / sizeof(arr[9]);
	my_bubble_sort(arr,sz);
	for (i = 0; i < sz - 1; )
	{
		if (arr[i] == arr[i + 1])
		{
			i+=2;
		}
		else
		{
			printf("%d", arr[i]);
			i++;
		}
	}
	return 0;
}
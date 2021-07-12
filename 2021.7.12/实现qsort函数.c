#include<stdio.h>
void swap(char* e1, char* e2, int wide)
{
	int i = 0;
	for (i = 0; i < wide; i++)
	{
		char t = 0;
		t = *e1;
		*e1 = *e2;
		*e2 = t;
		e1++;
		e2++;
	}
}
void bubble_sort(void* base, int size, int bit, int(*cmp)(const void* e1,const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (cmp((char*)base + j * bit, (char*)base + (j + 1) * bit)>0)
			{
				swap((char*)base + j * bit, (char*)base + (j + 1) * bit, bit);
			}
		}
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void text1()
{
	int i = 0;
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	text1();
	return 0;
}
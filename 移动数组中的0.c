#include<stdio.h>
void movezero(int arr[],int sz)
{
	int slow = 0;
	int fast = 0;
	//while (fast != sz)
	//{
	//	if (arr[slow] == 0)慢的指向0就等待被替换
	//	{
	//		if (arr[fast] != 0)
	//		{
	//			int t = arr[slow];
	//			arr[slow] = arr[fast];
	//			arr[fast] = t;
	//			slow++;
	//			fast++;
	//		}
	//		else
	//		{
	//			fast++;
	//		}
	//	}
	//	else
	//	{
	//		slow++;
	//		fast++;
	//	}
	//}
	while(fast<sz)
	{
		if(arr[fast])//遇到0slow指针就停下来，fast指针继续向前，遇到非0时，与slow进行交换，两个指针都向前移
		{
			int t=arr[slow];
			arr[slow] = arr[fast];
			arr[fast] = t;
			slow++;
		}
		fast++;
	}
}
void print(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i  sz; i++)
	{
		printf(%d , arr[i]);
	}
}
int main()
{
	int arr1[] = { 1,2,0,3,0,5,0 };
	int arr2[] = { 0,3,4,0,2,0,0,0 };
	int sz1 = sizeof(arr1)  sizeof(arr1[0]);
	int sz2 = sizeof(arr2)  sizeof(arr2[0]);
	movezero(arr1, sz1);
	print(arr1,sz1);
	printf(n);
	movezero(arr2, sz2);
	print(arr2, sz2);
	return 0;
}
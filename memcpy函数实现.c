//memcpyº¯ÊıÊµÏÖ
#include<stdio.h>
#include<assert.h>
#include<string.h>
void* my_memcpy(void* dest, void* src, int size)
{
	assert(dest && src);
	char* ret = (char*)dest;
	while (size--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[] = { 2,3,4,5,6,7 };
	my_memcpy(arr1, arr2, sizeof(arr2));
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<assert.h>
void swap_str(char* p, int sz)
{
	assert(p != NULL);
	int i = 0;
	for (i = 0; i < sz / 2; i++)
	{
		char t = 0;
		t = *(p + i);
		*(p + i) = *(p + sz - 1 - i);
		*(p + sz - 1 - i) = t;
	}
}
int main()
{
	char arr[] = "abcdef";
	int sz = strlen(arr);
	swap_str(arr, sz);
	printf("%s\n", arr);
	return 0;
}
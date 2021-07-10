#include<stdio.h>
#include<assert.h>
void my_strcpy(char* destination, char* source)
{
	assert(*destination != NULL);
	assert(*source != NULL);
	while (*destination++ = *source++)
	{
		;
	}
}
int main()
{
	char arr1[] = "%%%%%%%%%%%%";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}
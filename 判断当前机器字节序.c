#include<stdio.h>
int main()
{
	int i=1;
	char* p = (char*)&i;
	if (*p == 1)
		printf("Ð¡¶Ë\n");
	else
		printf("´ó¶Ë\n");
	return 0;
}
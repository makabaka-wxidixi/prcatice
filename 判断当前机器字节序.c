#include<stdio.h>
int main()
{
	int i=1;
	char* p = (char*)&i;
	if (*p == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}
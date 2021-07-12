#include<stdio.h>
void menu()
{
	printf("******************************\n");
	printf("*****1,add         2,sub *****\n");
	printf("*****3,mul         4,div *****\n");
	printf("*****5,xor         0,exit*****\n");
	printf("******************************\n");
}
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}
int main()
{
	int input;
	int x;
	int y;
	int (*pfunt[])(int, int) = { 0, add, sub, mul, div, Xor };
	menu();
	do
	{
		printf("��ѡ��\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 5)
		{
			printf("������������:>");
			scanf("%d%d", &x, &y);
			printf("��Ϊ%d\n", pfunt[input](x, y));
		}
		else if (input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	} while (input);
	return 0;
}
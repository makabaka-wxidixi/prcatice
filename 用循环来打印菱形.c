#include<stdio.h>
void print_upper(int n)
{
	int j = 1;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int m = 0;
		for (m = 0; m < n - i; m++)
		{
			printf(" ");
		}
		for (m = 0; m < j; m++)
		{
			printf("*");
		}
		printf("\n");
		j += 2;
	}
}
void print_mid(int n)
{
	int i = 0;
	for (i = 0; i < 2 * n + 1; i++)
	{
		printf("*");
	}
	printf("\n");
}
void print_lower(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2*(n-i)-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void test(int n)
{
	print_upper(n);//打印上半区
	print_mid(n);//打印最长行
	print_lower(n);//打印下半区
}
int main()
{
	int n;
	printf("输入一个数字n，将会得到一个行数为2n+1的菱形\n");
	scanf("%d", &n);
	test(n);
	return 0;
}
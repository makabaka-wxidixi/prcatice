
#include<stdio.h>
#include<stdlib.h>
void print_fun(char** arr, int input)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
void upper_half(int y, char** arr)//y=n/2
{
	int i = 0;
	int r = 1;
	for (i = 0; i < y; i++)
	{
		int j = 0;
		int left = y - i;
		for (j = 0; j < r; j++)
		{
			*(arr[i]+(left+j)) = '*';
		}
		r += 2;
	}
}
void mid(int n,char** arr)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		arr[n / 2][i] = '*';
	}
}
void lower_half(int y, char** arr)//y=n/2,行数
{
	int r = 1;
	int i = 0;
	for (i = 0; i < y; i++)
	{
		int left = y - i;
		int j = 0;
		for (j = 0; j < r; j++)
		{
			arr[2 * y - i][left + j] = '*';
		}
		r += 2;
	}
}
char** CrearArr(int n)//动态二维数组
{
	char** arr = (char**)malloc(sizeof(char*) * n);
	if (arr == NULL)	return NULL;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * n);
		if (arr[i] == NULL)		return NULL;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = ' ';//初始化为空格
		}
	}
	return arr;
}
void test(int n)//n为奇数
{
	int i=0;
	char** arr=CreatArr(n);
	upper_half(n / 2,arr);//上半区
	mid(n, arr);//中间
	lower_half(n / 2, arr);//下半区
	print_fun(arr,n);//打印函数
	for (i = 0; i < n; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}
int main()
{
	int n;
	printf("打印一个n行的菱形\n输入n的值\n注意：n应该为奇数\n");
	do
	{
		scanf("%d", &n);
		if (n % 2 == 0)
		{
			printf("应该输入奇数\n请重新输入\n");
		}
		else
		{	
			test(n);
		}

	} while (n);

	return 0;
}
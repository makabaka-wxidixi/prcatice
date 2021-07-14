#define row 9
#define lin 9
#include<stdio.h>
void itl_fun(char arr[row][lin])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void print_fun(char arr[row][lin])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
void upper_half(int y, char arr[row][lin])//y=n/2
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
void mid(int n,char arr[row][lin])
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		arr[n / 2][i] = '*';
	}
}
void lower_half(int y, char arr[row][lin])//y=n/2,行数
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
void test(int n)//n为奇数
{
	char arr[row][lin];
	itl_fun(arr);//初始化函数，将数组都初始化为' '
	upper_half(n / 2,arr);//上半区
	mid(n, arr);//中间
	lower_half(n / 2, arr);//下半区
	print_fun(arr);//打印函数
}
int main()
{
	int n;
	printf("打印一个n行的菱形\n输入n的值\n注意：n应该为奇数\n");
	scanf("%d", &n);
	do
	{

		if (n / 2 == 0)
		{
			printf("应该输入奇数\n请重新输入\n");
		}
		else
		{	
			test(n);
		}

	} while (n / 2 == 0);

	return 0;
}
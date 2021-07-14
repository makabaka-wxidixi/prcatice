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
void lower_half(int y, char arr[row][lin])//y=n/2,����
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
void test(int n)//nΪ����
{
	char arr[row][lin];
	itl_fun(arr);//��ʼ�������������鶼��ʼ��Ϊ' '
	upper_half(n / 2,arr);//�ϰ���
	mid(n, arr);//�м�
	lower_half(n / 2, arr);//�°���
	print_fun(arr);//��ӡ����
}
int main()
{
	int n;
	printf("��ӡһ��n�е�����\n����n��ֵ\nע�⣺nӦ��Ϊ����\n");
	scanf("%d", &n);
	do
	{

		if (n / 2 == 0)
		{
			printf("Ӧ����������\n����������\n");
		}
		else
		{	
			test(n);
		}

	} while (n / 2 == 0);

	return 0;
}
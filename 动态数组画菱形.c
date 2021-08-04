
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
void lower_half(int y, char** arr)//y=n/2,����
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
char** CrearArr(int n)//��̬��ά����
{
	char** arr = (char**)malloc(sizeof(char*) * n);
	if (arr == NULL)	return NULL;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * n);
		if (arr[i] == NULL)		return NULL;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = ' ';//��ʼ��Ϊ�ո�
		}
	}
	return arr;
}
void test(int n)//nΪ����
{
	int i=0;
	char** arr=CreatArr(n);
	upper_half(n / 2,arr);//�ϰ���
	mid(n, arr);//�м�
	lower_half(n / 2, arr);//�°���
	print_fun(arr,n);//��ӡ����
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
	printf("��ӡһ��n�е�����\n����n��ֵ\nע�⣺nӦ��Ϊ����\n");
	do
	{
		scanf("%d", &n);
		if (n % 2 == 0)
		{
			printf("Ӧ����������\n����������\n");
		}
		else
		{	
			test(n);
		}

	} while (n);

	return 0;
}
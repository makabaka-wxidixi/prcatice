#include<stdio.h>
int main()
{
	int arr[20][20] = { 0 };
	int i = 0;
	int J = 0;
	int n;
	printf("����һ��n,��ӡһ��n�е��������(n<=20)");
	scanf("%d", &n);
	for (i = 0; i < n; i++)//������
	{
		int j = 0;
		for (j = 0; j < i + 1; j++)
		{
			if (j == 0 || j == i)//��ӡ�߽�
			{
				arr[i][j] = 1;
			}
			if (i > 1 && j > 0)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];//����
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (J = 0; J < i + 1; J++)
		{
			printf("%d\t", arr[i][J]);
		}
		printf("\n");
	}
	return 0;
}
#include<stdio.h>
int sum(int a, int n)
{
	int i = 0;
	int sum = 0;
	int b = 0;
	for (i = 0; i < n; i++)
	{
		b = b * 10 + a;
		sum += b;
	}
	return sum;
}
int main()
{
	int SN;
	int a;
	int n;
	printf("���磺a=2,n=3,���Եõ�2+22+222�ĺ�\n");
	printf("������a��n\n");
	scanf("%d%d", &a,&n);
	SN = sum(a, n);
	printf("%d\n", SN);
	return 0;
}
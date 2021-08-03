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
	printf("例如：a=2,n=3,可以得到2+22+222的和\n");
	printf("请输入a和n\n");
	scanf("%d%d", &a,&n);
	SN = sum(a, n);
	printf("%d\n", SN);
	return 0;
}
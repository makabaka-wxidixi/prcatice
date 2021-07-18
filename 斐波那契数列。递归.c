#include<stdio.h>
int Fibonacci(int n)
{
	while (n)
	{
		if (n == 2)
			return 1;
		if (n == 1)
			return 0;
		if (n > 2)
			return Fibonacci (n-1)+Fibonacci (n-2);
	}
}
int main()
{
	int ret = 0;
	int n;
	printf("斐波那契数列\n求第n位");
	scanf("%d", &n);
	ret = Fibonacci(n);
	printf("%d\n", ret);
	return 0;
}
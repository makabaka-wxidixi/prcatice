#include<stdio.h>
int Fibonacci(int n)
{
	if(n<=1)
		return n;
	if (n > 1)
		return Fibonacci (n-1)+Fibonacci (n-2);
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
#include<stdio.h>
int Fibonacci(int n)
{
		if (n == 1)
			return 1;
		if (n <= 0)
			return 0;
		if (n > 1)
			return Fibonacci (n-1)+Fibonacci (n-2);
}
int main()
{
	int ret = 0;
	int n;
	printf("쳲���������\n���nλ");
	scanf("%d", &n);
	ret = Fibonacci(n);
	printf("%d\n", ret);
	return 0;
}
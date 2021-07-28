int Fibonacci(int n)
{
	if (n <= 1)//如果是前两位，直接返回就行
		return n;
	int sum = 0;
	int a = 0;//否则就创立连个变量来代替n=0和n=1
	int b = 1;
	for (int i = 1; i < n; i++)
	{
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}
int main()
{
	int ret = 0;
	int n = 5;
	printf("斐波那契数列\n求第n位");
	scanf("%d", &n);
	ret = Fibonacci(n);
	printf("%d\n", ret);
	return 0;
}
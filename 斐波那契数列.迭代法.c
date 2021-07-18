int Fibonacci2(int n)
{
	int x = 0;
	int y = 1;
	int i = 1;
	int ret = 0;
	for (i = 0; i <= n; i++)
	{
		if (i == 0)
			ret = 0;
		else if (i == 1)
			ret = 1;
		else
		{
			ret = x + y;
			x = y;
			y = ret;
		}
	}
	return ret;
}
int main()
{
	int ret = 0;
	int n = 5;
	printf("斐波那契数列\n求第n位");
	scanf("%d", &n);
	//ret = Fibonacci1(n);
	ret = Fibonacci2(n);
	printf("%d\n", ret);
	return 0;
}
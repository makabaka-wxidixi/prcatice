int Fibonacci(int n)
{
	if (n <= 1)//�����ǰ��λ��ֱ�ӷ��ؾ���
		return n;
	int sum = 0;
	int a = 0;//����ʹ�����������������n=0��n=1
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
	printf("쳲���������\n���nλ");
	scanf("%d", &n);
	ret = Fibonacci(n);
	printf("%d\n", ret);
	return 0;
}
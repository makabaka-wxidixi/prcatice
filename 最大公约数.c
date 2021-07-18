#include<stdio.h>
int max_com_div(int n, int m)
{
	int rem = 0;
	if (n < m)
	{
		int mid = 0;
		mid = n;
		n = m;
		m = mid;
	}
	while (1)
	{
		rem = n % m;
		if (rem == 0)
			return m;
		else
		{
			n = m;
			m = rem;
		}
	}
}
int main()
{
	int n = 0;
	int m = 0;
	int ret = 0;
	printf("求两个数的最大公约数\n");
	scanf("%d%d", &n, &m);
	ret = max_com_div(n, m);
	printf("%d\n", ret);
	return 0;
}
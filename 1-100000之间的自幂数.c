#include<stdio.h>
#include<math.h>
int Pow(int i)
{
	int n = 1;
	while (i / 10)
	{
		n++;
		i /= 10;
	}
	return n;
}
int main()
{
	int i;
	for (i = 1; i <= 100000; i++)
	{	
		int j = i;
		int sum = 0;
		int n = Pow(i);//Çó´ÎÃÝ
		while (j)
		{
			int w = 0;
			int m = j % 10;
			j /= 10;
			w = pow(m,n);
			sum += w;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
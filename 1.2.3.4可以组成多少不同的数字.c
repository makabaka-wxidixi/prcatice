//有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
#include<stdio.h>
int main()
{
	int count=0;
	int i = 0;
	for (i = 1; i <= 4; i++)
	{
		int j = 0;
		for (j = 1; j <= 4; j++)
		{
			int k = 0;
			for (k = 1; k <= 4; k++)
			{
				if (i != j && j != k && i != k)
				{
					count++;
					printf("%d%d%d", i, j, k);
					printf("\n");
				}
			}
		}
	}
	printf("%d",count);
	return 0;
}
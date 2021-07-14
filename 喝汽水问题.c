#include<stdio.h>
int drink_max(int bottle, int exc)
{
	int count = bottle;
	while (bottle > 1)
	{
		if (bottle % 2 == 0)
		{
			bottle = bottle / exc;
			count += bottle;
		}
		else
		{
			bottle = bottle - 1;
			bottle = bottle / exc;
			count += bottle;
			bottle=bottle+1;
		}
	}
	return count；
}
int main()
{
	int drink;
	int money;
	int exchange;
	printf("一瓶汽水1元，两个瓶子兑换一瓶汽水，给20元可以喝多少瓶\n");
	printf("请决定给多少钱，并规定兑换规则\n");
	scanf("%d%d", &money, &exchange);
	drink=drink_max(money, exchange);
	printf("%d\n", drink);
	return 0;
}

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
	return count��
}
int main()
{
	int drink;
	int money;
	int exchange;
	printf("һƿ��ˮ1Ԫ������ƿ�Ӷһ�һƿ��ˮ����20Ԫ���Ժȶ���ƿ\n");
	printf("�����������Ǯ�����涨�һ�����\n");
	scanf("%d%d", &money, &exchange);
	drink=drink_max(money, exchange);
	printf("%d\n", drink);
	return 0;
}

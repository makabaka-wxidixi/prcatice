//猜凶手
//a：不是我
//b: 是c
//c：是d
//d：c在胡说
//一直三个人说了真话，一个人说了假话
#include<stdio.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("凶手是%c\n", killer);
		}
	}
	return 0;
}
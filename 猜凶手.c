//������
//a��������
//b: ��c
//c����d
//d��c�ں�˵
//һֱ������˵���滰��һ����˵�˼ٻ�
#include<stdio.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("������%c\n", killer);
		}
	}
	return 0;
}
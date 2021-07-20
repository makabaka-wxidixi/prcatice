#include<stdio.h>
#include<assert.h>
#include<string.h>
int cmp(char* sourse, char* change)//�ж������ַ����Ƿ���ȣ���ȷ���1
{
	int i = 0;
	int sz = strlen(sourse);
	while (i < sz)
	{
		if (*(sourse + i) != *(change + i))
			return 0;
		i++;
	}
	return 1;
}
void left_reversal(char* sourse, int step)//�Ʋ�����
{
	int i = 0;
	char ch = 0;
	int sz = strlen(sourse);
	for (i = 0; i < step; i++)
	{
		ch = *sourse;//��һ��Ԫ�ش�����
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			*(sourse + j) = *(sourse + 1 + j);
		}
		*(sourse + sz - 1) = ch;
	}
}
int is_reversal_left(char* sourse, char* change)//����0��˵����������������
{
	assert(sourse&&change);
	assert(strlen(sourse) == strlen(change));
	int i = 0;
	for (i = 0; i < strlen(sourse); i++)
	{
		left_reversal(sourse, 1);//�Ʋ�����
		if(strcmp(sourse, change)==1)//�ж�sourse,change�Ƿ���ȣ���ȷ���1��
		{
			return1;
		}
	}
	return 0;
}
int main()
{
	char sourse[] = "abcdefg";
	char change[] = "gabcdef";
	int ret = is_reversal_left(sourse, change);
	if (ret == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}
#include<stdio.h>
#include<assert.h>
#include<string.h>
int cmp(char* sourse, char* change)//判断两个字符串是否相等，相等返回1
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
void left_reversal(char* sourse, int step)//移步函数
{
	int i = 0;
	char ch = 0;
	int sz = strlen(sourse);
	for (i = 0; i < step; i++)
	{
		ch = *sourse;//第一个元素存起来
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			*(sourse + j) = *(sourse + 1 + j);
		}
		*(sourse + sz - 1) = ch;
	}
}
int is_reversal_left(char* sourse, char* change)//返回0就说明不是左旋得来的
{
	assert(sourse);
	assert(change);
	assert(strlen(sourse) == strlen(change));
	int i = 0;
	int sz = strlen(sourse);
	for (i = 0; i < sz; i++)
	{
		int tmp = 0;
		left_reversal(sourse, 1);//移步函数
		tmp = cmp(sourse, change);//判断sourse,change是否相等，相等返回1；
		if (tmp == 1)
			return 1;
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
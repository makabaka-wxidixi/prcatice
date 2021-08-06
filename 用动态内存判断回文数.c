#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int digit(int n)
{
	int i = 1;
	while (n /= 10)
	{
		i++;
	}
	return i;
}
int main()
{
	int i = 0;
	int ret = 0;
	int input = 0;
	int *pa=(int *)malloc(8);//先分配8个字节的大小
	if(pa==NULL)
	{
		perror("pa");
		return 0;
	}
	scanf("%d", &input);
	if(input<0)
		printf("不是回文数\n");
	else
	{
		ret = digit(input);//计算输入数字的位数
		if (digit == 1)
			printf("是回文数\n");
		else
		{
			while (input)
			{
				if (i > 1)//判断空间是否够用
				{
					int* paa = realloc(pa, 4 * (i + 1));//扩容，内存不够就扩4个字节
					if (paa == NULL)//判断指针有效性
					{
						perror("paa");
						return 0;
					}	
					pa = paa;
				}
				*(pa + i) = input % 10;
				input /= 10;
				i++;
			}
			for (i = 0; i < ret / 2; i++)
			{
				if (*(pa + i) != *(pa + ret - 1 - i))//判断对应位置数字是否相等
				{
					printf("不是回文数\n");
					free(pa);//释放空间
					pa = NULL;//pa指针至成空指针
					return 0;
				}
			}
			printf("是回文数\n");
		}
	}
	free(pa);//释放空间
	pa = NULL;//pa指针至成空指针
	return 0;
}
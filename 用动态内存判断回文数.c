#include<stdio.h>
#include<math.h>
#include<string.h>
int digit(int n)
{
	if (n >= 0 && n < 10)
		return 1;
	else
	{
		int m = 0;
		while (n)
		{
			n /= 10;
			m++;
		}
		return m;
	}
}
int main()
{
	int i = 0;
	int input = 0;
	int cinput;
	int *pa=(int *)malloc(8);//先分配8个字节的大小
	scanf("%d", &input);
	int dig = digit(input);//计算输入数字的位数
	cinput = input;//输入数字拷贝
	if (dig == 1)
		printf("是\n");
	else
	{
		while (dig)
		{
			if (i > 1)
			{
				int* paa = realloc(pa, 4 * (i + 1));//扩容，内存不够就扩4个字节
				if (paa == NULL)//判断指针有效性
				{
					return 0;
				}
				pa = paa;
			}
			*(pa + i) = cinput % 10;
			cinput /= 10;
			i++;
			dig--;
		}
		for (i = 0; i < digit(input) / 2; i++)
		{
			if (*(pa + i) != *(pa + digit(input) - 1 - i))//判断对应位置数字是否相等
			{
				printf("不是\n");
				free(pa);
				pa = NULL;
				return 0;
			}
		}
		printf("是\n");
	}
	free(pa);//释放空间
	pa = NULL;//pa指针至成空指针，防止污染
	return 0;
}
#include<stdio.h>
#include<math.h>
#include<string.h>
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
	int input = 0;
	int cinput;
	int *pa=(int *)malloc(8);//�ȷ���8���ֽڵĴ�С
	scanf("%d", &input);
	int dig = digit(input);//�����������ֵ�λ��
	cinput = input;//�������ֿ���
	if (dig == 1)
		printf("��\n");
	else
	{
		while (dig)
		{
			if (i > 1)
			{
				int* paa = realloc(pa, 4 * (i + 1));//���ݣ��ڴ治������4���ֽ�
				if (paa == NULL)//�ж�ָ����Ч��
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
			if (*(pa + i) != *(pa + digit(input) - 1 - i))//�ж϶�Ӧλ�������Ƿ����
			{
				printf("����\n");
				free(pa);
				pa = NULL;
				return 0;
			}
		}
		printf("��\n");
	}
	free(pa);//�ͷſռ�
	pa = NULL;//paָ�����ɿ�ָ�룬��ֹ��Ⱦ
	return 0;
}
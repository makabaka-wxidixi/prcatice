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
	int *pa=(int *)malloc(8);//�ȷ���8���ֽڵĴ�С
	scanf("%d", &input);
	ret = digit(input);//�����������ֵ�λ��
	if (dig == 1)
		printf("�ǻ�����\n");
	else
	{
		while (input)
		{
			if (i > 1)//�жϿռ��Ƿ���
			{
				int* paa = realloc(pa, 4 * (i + 1));//���ݣ��ڴ治������4���ֽ�
				if (paa == NULL)//�ж�ָ����Ч��
					return 0;
				else	
					pa = paa;
			}
			*(pa + i) = input % 10;
			input /= 10;
			i++;
		}
		for (i = 0; i < ret / 2; i++)
		{
			if (*(pa + i) != *(pa + ret - 1 - i))//�ж϶�Ӧλ�������Ƿ����
			{
				printf("���ǻ�����\n");
				free(pa);//�ͷſռ�
				pa = NULL;//paָ�����ɿ�ָ��
				return 0;
			}
		}
		printf("�ǻ�����\n");
	}
	free(pa);//�ͷſռ�
	pa = NULL;//paָ�����ɿ�ָ��
	return 0;
}
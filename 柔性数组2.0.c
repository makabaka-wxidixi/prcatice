#include<stdio.h>
#include<stdlib.h>
struct S
{
	int a;
	int arr[];
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//����ṹ���С
	ps->a = 100;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	struct S* ptr = (struct S*)realloc(ps, 44);//�����ṹ���ڲ������С
	if (ptr != NULL)
	{
		ps = ptr;
		for (i = 5; i < 10; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", ps->arr[i]);
		}
	}
	free(ps);//�ͷ�
	ps = NULL;
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = malloc(5 * sizeof(int));//������5��int��С
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	int *ptr = realloc(ps->arr, 10 * sizeof(int));//�ṹ��������ı��10��int��С�������5��int
	if (ptr != NULL)
	{
		ps->arr = ptr;
		for (i = 5; i < 10; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", ps->arr[i]);
		}
	}
	free(ps->arr);//�ͷſռ�
	ps->arr = NULL;
	free(ps);//�ͷſռ�
	ps = NULL;
	return 0;
}
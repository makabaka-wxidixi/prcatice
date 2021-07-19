#include<stdio.h>
#include<stdlib.h>
struct S
{
	int a;
	int arr[];
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//定义结构体大小
	ps->a = 100;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	struct S* ptr = (struct S*)realloc(ps, 44);//调整结构体内部数组大小
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
	free(ps);//释放
	ps = NULL;
	return 0;
}
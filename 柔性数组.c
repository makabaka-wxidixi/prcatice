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
	ps->arr = malloc(5 * sizeof(int));//给数组5个int大小
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	//for (i = 0; i < 5; i++)
	//{
	//	printf("%d ", ps->arr[i]);
	//}
	//调整大小
	int *ptr = realloc(ps->arr, 10 * sizeof(int));//结构体内数组改变成10个int大小，再添加5个int
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
	free(ps->arr);//释放空间
	ps->arr = NULL;
	free(ps);//释放空间
	ps = NULL;
	return 0;
}
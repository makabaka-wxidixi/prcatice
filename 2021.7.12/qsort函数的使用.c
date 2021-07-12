#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stu
{
	char name[10];
	int age;
}stu;
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void text1()
{
	int i = 0;
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
}
int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;
}
void text2()
{
	int i = 0;
	float f[] = { 1.2,2.3,3.4,4.5,5.6 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}
int cmp_struct_age(const void* e1, const void* e2)
{
	return ((stu*)e1)->age - ((stu*)e2)->age;
}
int cmp_struct_name(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->name, ((stu *) e2)->name);
}
void text3()
{
	stu ss[3] = { {"Õı∏’",21},{"¡ıΩ‹",20},{"’≈»˝",18} };
	int sz = sizeof(ss) / sizeof(ss[0]);
	qsort(ss, sz, sizeof(ss[0]), cmp_struct_name);
}
int main()
{
	text1();
	printf("\n");
	text2();
	printf("\n");
	text3();
	return 0;
}
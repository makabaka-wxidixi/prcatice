#include<stdio.h>
struct S
{
	char name;
	int age;
	char tel;
};
#define offsetof(struct_name,struct_type) (int)&(((struct_name*)0)->struct_type)
int main()
{
	printf("%d\n", offsetof(struct S, name));
	printf("%d\n", offsetof(struct S, age));
	printf("%d\n", offsetof(struct S, tel));
	return 0;
}
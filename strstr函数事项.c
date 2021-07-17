#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* r1, const char* r2)
{
	assert(r1 && r2);
	char* p1 = (char*)r1;
	char* p2 = (char*)r2;
	if (*r2 == '\0')
		return p1;
	while (p1)
	{
		char* s1 = p1;
		char* s2 = p2;
		while (*s1 == *s2 && *s2 && *s1)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return p1;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		p1++;
	}
}
int main()
{
	const char* r1 = "abcdefg";
	const char* r2 = "cde";
	char* ret = NULL;
	ret = my_strstr(r1, r2);
	if (ret)
	{
		printf("找到了%s\n", ret);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}
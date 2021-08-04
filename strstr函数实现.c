#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* r1, const char* r2)
{
	assert(r1 && r2);
	char* p1 = (char*)r1;
	char* p2 = (char*)r2;
	char* s = p1;
	if (*r2 == '\0')
		return p1;
	while (r1)
	{
		while (*p1 == *p2 && *p2 && *p1)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return --s;
		}
		if (*p1 == '\0')
		{
			return NULL;
		}
		p1 = s++;
		p2 = r2;
	}
}
int main()
{
	const char* r1 = "abcdefg";
	const char* r2 = "cde";
	char* ret = my_strstr(r1, r2);
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
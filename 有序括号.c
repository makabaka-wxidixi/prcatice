#include<stdio.h>
#include<assert.h>
char pairs(char s)
{
	if (s == ')') return '(';
	if (s == ']') return '[';
	if (s == '}') return '{';
	return 0;
}
void isvalid(char *s)
{
	assert(s);
	int n = strlen(s);
	char stack[10];
	if (n % 2 == 1)//奇数，肯定有不匹配的
	{
		printf("错错错\n");
		return;
	}
	else
	{
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			char ch = pairs(s[i]);
			if (ch)//如果是右括号就进行比较
			{
				if (ch != stack[j - 1] || j == 0)//匹配不上或者栈是空
				{
					printf("不是\n");
					return;
				}
				j--;
			}
			else//如果是左括号就入栈
				stack[j++] = s[i];
		}
		printf("是的\n");
		return;
	}
}
int main()
{
	char arr1[] = "{[()]}";
	char arr2[] = "()[]{}";
	char arr3[] = ")(";
	isvalid(arr1);
	isvalid(arr2);
	isvalid(arr3);
	return 0;
}
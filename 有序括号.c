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
	if (n % 2 == 1)//�������϶��в�ƥ���
	{
		printf("����\n");
		return;
	}
	else
	{
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			char ch = pairs(s[i]);
			if (ch)//����������žͽ��бȽ�
			{
				if (ch != stack[j - 1] || j == 0)//ƥ�䲻�ϻ���ջ�ǿ�
				{
					printf("����\n");
					return;
				}
				j--;
			}
			else//����������ž���ջ
				stack[j++] = s[i];
		}
		printf("�ǵ�\n");
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
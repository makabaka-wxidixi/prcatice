#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reversal_word1(char* arr)
{
	int lenth = strlen(arr);
	int i = 0;
	while (i < lenth)
	{
		int start = i;//���ڼ�¼��������ĸ
		while (i < lenth && arr[i] != ' ')//�����ַ�����β\0�Ϳո��ֹͣ
		{
			i++;
		}
		int left = start;
		int right = i - 1;
		while (left < right)
		{
			char tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
		while (arr[i] == ' ')
		{
			i++;
		}
	}
}
char* reversal_word2(char arr[])
{
	int lenth = strlen(arr);//�ַ�������
	char* str = (char*)malloc(lenth + 1);//Ҫ���Ᵽ��һ��\0
	int i = 0;
	str[lenth] = 0;
	while (i<lenth)
	{
		int start = i;
		while (i < lenth && arr[i] != ' ')
		{
			i++;
		}
		for (int p = start; p < i; p++)
		{
			str[p] = arr[i - 1 - p + start];
		}
		while (arr[i] == ' ')
		{
			str[i] = ' ';
			i++;
		}
	}
	return str;
}
int main()
{
	char arr[] = "abcdef ghijk lmno pqrst uvwxyz";
	reversal_word1(arr);
	printf("%s", arr);
	printf("\n");
	char*arr1=reversal_word2(arr);
	printf("%s", arr1);
	return 0;
}
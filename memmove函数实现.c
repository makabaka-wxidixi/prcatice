#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memmove(void* dest, const void* src, int size)
{
	assert(dest && src);
	char* ret = dest;  //����dest��ַ
	if (src < dest)//��Դ�ַ����׵�ַС��Ŀ���ַ����׵�ַʱ�����ȴ��ұ߿�ʼ��ֵ
	{
		while (size--)
		{
			*((char*)dest + size) = *((char*)src + size);
		}
	}
	else//��Դ�ַ����׵�ַ����Ŀ���ַ����׵�ַʱ�����ȴ���߿�ʼ��ֵ
	{
		while (size--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	return ret;
}
int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr+6, 16);
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}
#include<stdio.h>
int ispali(int n)
{
	if (n < 0)	return 0;
	if (n >= 0 && n < 10) return 1;
	int arr[30] = { 0 };
	int count = 1, i = 0, left = 0, right = 0;//位数，数组下标，左标记，右标记
	arr[i++] = n % 10;
	while (n / 10)//求数字的位数
	{
		n /= 10;
		arr[i++] = n % 10;
		count++;//位数
	}
	right = count-1;
	while (left <= right)
	{
		if (arr[left++] != arr[right--])
			return 0;
	}
	return 1;
}
int main()
{
	int n = 122454321;
	n = 12321;
	n = -12321;
	n = 65456;
	n = 1;
	n = -1;
	int ret = ispali(n);
	if (ret)
		printf("%d是回文数\n", n);
	else
		printf("%d不是回文数\n", n);
	return 0;
}
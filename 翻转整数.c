#include<stdio.h>	
#define INT_MIN (-_CRT_INT_MAX)-1
int reverse(int a)
{
	int rev = 0;
	while (a != 0)
	{
		if (rev<INT_MIN / 10 || rev>_CRT_INT_MAX / 10)
			return 0;
		int dig = a % 10;
		a /= 10;
		rev = rev * 10 + dig;
	}
	return rev;
}
int main()
{
	int a = 2147483647;
	scanf("%d", &a);
	int ret = reverse(a);
	printf("%d\n", ret);
	return 0;
}
#include<stdio.h>
#include<math.h>
#include<time.h>
clock_t start, stop;
double duration;
#define MAXN 10//最大阶数+1
double function1(int n, double a[], double x)//n是最大平方数，a[]是系数
{
	int i = 0;
	double p = a[0];
	for (i = 1; i <= n; i++)
		p += (a[i] * pow(x, i));
	return p;
}
double function2(int n, double a[], double x)//秦九韶算法
{
	int i = 0;
	double p = a[n];
	for (i = n - 1; i >= 0; i--)
		p = (a[i] + p * x);
	return p;
}
void function3(clock_t start, clock_t stop)
{
	double i = 0;
	i = ((double)(stop - start)) / CLK_TCK;//函数单词运行的时间
	printf("ticks= %lf\n", (double)(stop - start));
	printf("duration= %lf\n", i);
}
int main()
{
	int i = 0;
	double arr[MAXN];
	for (i = 0; i < MAXN; i++)
		arr[i] = i;
	start = clock();
	for (i = 0; i < 1000000; i++)
		function1(MAXN - 1, arr, 1.1);
	stop = clock();
	function3(start, stop);

	start = clock();
	for (i = 0; i < 1000000; i++)
		function2(MAXN - 1, arr, 1.1);
	stop = clock();
	function3(start, stop);
	return 0;
}
#include<stdio.h>
int isUgly(int n) {
    if (n == 1)    return 1;
    if (n == 0)    return 0;
    while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
    {
        if (n % 2 == 0)
            n /= 2;
        else if (n % 3 == 0)
            n /= 3;
        else if (n % 5 == 0)
            n /= 5;
        else;
    }
    if (n == 1)
        return 1;
    else
        return 0;
}

int nthUglyNumber(int n) {
    int idex = 0;//索引
    while (n--)//循环n次
    {
        int m = ++idex;//记录索引值
        while (1)
        {
            if (m % 2 == 0 || m % 3 == 0 || m % 5 == 0) {
                if (m % 2 == 0)   m /= 2;
                else if (m % 3 == 0)  m /= 3;
                else if (m % 5 == 0)  m /= 5;
                else;
            }
            else
            {
                if (m == 1)
                    break;
                else
                    m = ++idex;
            }
        }
    }
    return idex;
}

int main()
{
    int ret = 0;
    int input = 0;
    printf("输入一个数字，将会判断其是不是丑数");
    scanf("%d", &input);
    ret = isUgly(input);
    if (ret) printf("是丑数");
    else printf("不是丑数");
	printf("输入一个数字n，将会返回第n个丑数");
    scanf("%d", &input);
    ret = nthUglyNumber(input);
    printf("%d", ret);
    return 0;
}
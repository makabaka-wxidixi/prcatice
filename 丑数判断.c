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

int main()
{
    int ret = 0;
    int input = 0;
    printf("����һ�����֣������ж����ǲ��ǳ���");
    scanf("%d", &input);
    ret = isUgly(input);
    if (ret) printf("�ǳ���");
    else printf("���ǳ���");
    return 0;
}
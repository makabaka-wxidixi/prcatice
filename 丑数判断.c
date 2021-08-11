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
    int idex = 0;//����
    while (n--)//ѭ��n��
    {
        int m = ++idex;//��¼����ֵ
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
    printf("����һ�����֣������ж����ǲ��ǳ���");
    scanf("%d", &input);
    ret = isUgly(input);
    if (ret) printf("�ǳ���");
    else printf("���ǳ���");
	printf("����һ������n�����᷵�ص�n������");
    scanf("%d", &input);
    ret = nthUglyNumber(input);
    printf("%d", ret);
    return 0;
}
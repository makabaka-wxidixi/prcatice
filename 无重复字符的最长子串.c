#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
    if (*s == '\0') return 0;
    int len = strlen(s);
    if (len == 1)  return 1;
    int ps = 0, pf = 1, arr[99999], j = 0;

    while (*(s + pf) != '\0') {//���ʵ�\0ʱֹͣ
        if (*(s + ps) != *(s + pf)) {//����������ݲ�ͬ
            for (int i = ps + 1; i <= pf - 1; i++) {//��ps����һλ��ʼ��������pf�Ƚ�
                if (*(s + i) == *(s + pf)) {//���������ȵ�
                    arr[j++] = pf - ps;//��¼
                    ps = i + 1;//ps�ƶ�����ȵ���һλ
                    pf = ps;//pf�˵�ps
                    break;
                }
            }
            pf++;//pf��������֤��psǰ��
        }
        else {//���������ͬ��
            arr[j++] = pf - ps;//��¼
            ps++;//ps����ǰ��һλ
            pf = ps + 1;//pf��ǰpsһλ
        }
    }
    arr[j++] = pf - ps;
    for (int m = 0; m < j - 1; m++) {//ð������
        if (arr[m] > arr[m + 1])
        {
            int tmp = arr[m];
            arr[m] = arr[m + 1];
            arr[m + 1] = tmp;
        }
    }
    return arr[--j];
}
int main()
{
    int len = 0;
    char s1[] = "abcabcbb";
    char s2[] = "asdfwwgsadge";
    char s3[] = "jjjjasdfjjjadfl";
    len = lengthOfLongestSubstring(s1);
    printf("s1���ظ���ַ������ȣ�%d\n", len);
    len = lengthOfLongestSubstring(s2);
    printf("s2���ظ���ַ������ȣ�%d\n", len);
    len = lengthOfLongestSubstring(s3);
    printf("s3���ظ���ַ������ȣ�%d\n", len);
	return 0;
}
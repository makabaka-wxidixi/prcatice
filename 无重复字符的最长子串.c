#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
    if (*s == '\0') return 0;
    int len = strlen(s);
    if (len == 1)  return 1;
    int ps = 0, pf = 1, arr[99999], j = 0;

    while (*(s + pf) != '\0') {//访问到\0时停止
        if (*(s + ps) != *(s + pf)) {//如果两个内容不同
            for (int i = ps + 1; i <= pf - 1; i++) {//从ps的下一位开始遍历，与pf比较
                if (*(s + i) == *(s + pf)) {//如果遇到相等的
                    arr[j++] = pf - ps;//记录
                    ps = i + 1;//ps移动到相等的下一位
                    pf = ps;//pf退到ps
                    break;
                }
            }
            pf++;//pf自增，保证在ps前面
        }
        else {//如果碰到相同的
            arr[j++] = pf - ps;//记录
            ps++;//ps就向前移一位
            pf = ps + 1;//pf超前ps一位
        }
    }
    arr[j++] = pf - ps;
    for (int m = 0; m < j - 1; m++) {//冒泡排序
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
    printf("s1无重复最长字符串长度：%d\n", len);
    len = lengthOfLongestSubstring(s2);
    printf("s2无重复最长字符串长度：%d\n", len);
    len = lengthOfLongestSubstring(s3);
    printf("s3无重复最长字符串长度：%d\n", len);
	return 0;
}
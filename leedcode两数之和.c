#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {
    if (numsSize < 2) return NULL;
    int* arr = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (j == i)
                continue;
            int add = nums[i] + nums[j];
            if (add == target)
            {
                arr[0] = i;
                arr[1] = j;
            }
        }
    }
    return arr;
}

int main()
{
    int input = 0;
    int arr[] = { 2,5,7,3,1,8,4,9,6,12,16,11 };
    int sz = sizeof(arr) / sizeof(sizeof(int));
    printf("输入一个数，将会得到和为目标值的两个数的下标\n");
    scanf("%d", &(input));
    int* ret = twoSum(arr, sz, input);
    if (ret == NULL)
        printf("找不到\n");
    else
    {
        printf("%d ", *(ret));
        printf("%d\n", *(ret + 1));
    }
    return 0;
}
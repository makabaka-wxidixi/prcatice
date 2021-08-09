#include<stdio.h>
#include<stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1 == NULL || nums2 == NULL)    return 0;
    int* arr = (int*)malloc(sizeof(int) * (nums1Size + nums2Size + 1));
    if (arr == NULL)   return 0;
    int m2 = 0, n1 = 0;
    int i = 0;
    while (n1 < nums1Size && m2 < nums2Size)
    {
        if (nums1[n1] < nums2[m2])
            arr[i++] = nums1[n1++];
        else
            arr[i++] = nums2[m2++];
    }
    while (n1 < nums1Size)
        arr[i++] = nums1[n1++];
    while (m2 < nums2Size)
        arr[i++] = nums2[m2++];
    int left = 0;
    int right = i - 1;
    double mid = 0;
    while (left <= right)
    {
        mid = (arr[left++] + arr[right--]) / 2.0;
    }
    return mid;
}
int main()
{
    int arr1[] = { 1,2,3,4,5,6 };
    int arr2[] = { 3,4,5,6,7,8,9 };
    int sz1 = sizeof(arr1) / sizeof(arr1[0]);
    int sz2 = sizeof(arr2) / sizeof(arr2[0]);
    double ret = findMedianSortedArrays(arr1, sz1, arr2, sz2);
    printf("%f", ret);
	return 0;
}
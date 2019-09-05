#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// [1, 3, 4] --> [1, #, 3, #, 4, #]
// [2, 6] --> [2, #, 6, #]
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size) // 保证数组1一定最短
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    // Ci 为第i个数组的割
    // LMaxi为第i个数组割后的左元素
    // RMini为第i个数组割后的右元素
    int LMax1, LMax2,
        RMin1, RMin2,
        c1, c2,
        lo = 0,
        hi = 2 * nums1Size; // 我们目前是虚拟加了'#'所以数组1是2*n长度

    while (lo <= hi) // 二分
    {
        c1 = (lo + hi) / 2; // c1是二分的结果
        c2 = nums2Size + nums1Size - c1;

        LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * nums1Size) ? INT_MAX : nums1[c1 / 2];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * nums2Size) ? INT_MAX : nums2[c2 / 2];

        if (LMax1 > RMin2)
            hi = c1 - 1;
        else if (LMax2 > RMin1)
            lo = c1 + 1;
        else
            break;
    }

    return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}

int main(int argc, char **argv)
{
    int r1[] = {1};
    int r2[] = {2};

    int n1 = sizeof(r1) / sizeof(r1[0]);
    int n2 = sizeof(r2) / sizeof(r2[0]);

    printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45, 50};

    n1 = sizeof(ar1) / sizeof(ar1[0]);
    n2 = sizeof(ar2) / sizeof(ar2[0]);

    printf("Median is 17 = %f\n", findMedianSortedArrays(ar1, n1, ar2, n2));

    int ar11[] = {1, 12, 15, 26, 38};
    int ar21[] = {2, 13, 17, 30, 45};

    n1 = sizeof(ar11) / sizeof(ar11[0]);
    n2 = sizeof(ar21) / sizeof(ar21[0]);

    printf("Median is 16 = %f\n", findMedianSortedArrays(ar11, n1, ar21, n2));

    int a1[] = {1, 2, 5, 6, 8};
    int a2[] = {13, 17, 30, 45, 50};

    n1 = sizeof(a1) / sizeof(a1[0]);
    n2 = sizeof(a2) / sizeof(a2[0]);

    printf("Median is 10.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

    int a10[] = {1, 2, 5, 6, 8, 9, 10};
    int a20[] = {13, 17, 30, 45, 50};

    n1 = sizeof(a10) / sizeof(a10[0]);
    n2 = sizeof(a20) / sizeof(a20[0]);

    printf("Median is 9.5 = %f\n", findMedianSortedArrays(a10, n1, a20, n2));

    int a11[] = {1, 2, 5, 6, 8, 9};
    int a21[] = {13, 17, 30, 45, 50};

    n1 = sizeof(a11) / sizeof(a11[0]);
    n2 = sizeof(a21) / sizeof(a21[0]);

    printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a21, n2));

    return 0;
}

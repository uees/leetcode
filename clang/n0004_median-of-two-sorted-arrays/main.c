#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size) // ��֤����1һ�����
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    // Ci Ϊ��i������ĸ�
    // LMaxiΪ��i�����������Ԫ��
    // RMiniΪ��i�����������Ԫ��
    int LMax1, LMax2,
        RMin1, RMin2,
        c1, c2,
        lo = 0,
        hi = 2 * nums1Size; // ����Ŀǰ���������'#'��������1��2*n����

    while (lo <= hi) // ����
    {
        c1 = (lo + hi) / 2; // c1�Ƕ��ֵĽ��
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

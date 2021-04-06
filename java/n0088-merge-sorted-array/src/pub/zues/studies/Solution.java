package pub.zues.studies;

public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // 我们为两个数组分别设置一个指针 p1 与 p2 来作为队列的头部指针
        int p1 = 0, p2 = 0;
        // 定义一个用于排序的临时数组
        int[] sorted = new int[m + n];
        // 当前数字
        int current;
        while (p1 < m || p2 < n) {
            if (p1 == m) {  // nums1 已经遍历完
                current = nums2[p2++];
            } else if (p2 == n) {  // nums2 已经遍历完
                current = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                current = nums1[p1++];
            } else {
                current = nums2[p2++];
            }

            sorted[p1 + p2 - 1] = current;
        }

        System.arraycopy(sorted, 0, nums1, 0, m + n);
    }
}

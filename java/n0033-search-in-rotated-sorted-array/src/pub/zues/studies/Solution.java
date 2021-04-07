package pub.zues.studies;

public class Solution {
    // 暴力法
    public int search1(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }

    // 二分法
    public int search2(int[] nums, int target) {
        int length = nums.length;
        if (length == 0) {
            return -1;
        }

        if (length == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int left = 0, right = length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[0] <= nums[mid]) {  // 左边有序
                if (nums[0] <= target && target < nums[mid]) {  // target的值在左半边
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {  // 右半边有序
                if (nums[mid] < target && target <= nums[length - 1]) {  // target的值在右半边
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
}

package pub.zues.studies;

public class Solution {
    public int findMin(int[] nums) {
        int length = nums.length;
        // 如果只有一个元素 或者 已经有序，直接返回第一个
        if (length == 1 || nums[0] < nums[length - 1]) {
            return nums[0];
        }

        int left = 0, right = length - 1;
        while (left < right) {
            // 只有两位数时
            if (left == right - 1) {
                return Math.min(nums[left], nums[right]);
            }

            int mid = (left + right) / 2;

            // 分割后两边都有序, 或者一侧只有一个数（一个数时相等，如 [3,1,2]）
            if (nums[left] <= nums[mid - 1] && nums[mid + 1] <= nums[length - 1]) {
                return Math.min(nums[mid], nums[mid + 1]);
            }

            // 最小值在无序的一端
            if (nums[left] > nums[mid - 1]) {  // 左边无序
                right = mid - 1;
            } else {  // 右边无序
                left = mid + 1;
            }
        }

        return 0;
    }
}

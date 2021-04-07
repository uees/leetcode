package pub.zues.studies;

public class Solution {
    // 暴力法
    public boolean search1(int[] nums, int target) {
        for (int num : nums) {
            if (target == num) {
                return true;
            }
        }

        return false;
    }

    // 二分法
    public boolean search2(int[] nums, int target) {
        int length = nums.length;
        if (length == 0) {
            return false;
        }

        if (length == 1) {
            return nums[0] == target;
        }

        int left = 0, right = length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }

            // 例如 [3,1,2,3,3,3,3], target=2，首次二分时无法判断区间 [0,3] 和区间 [4,6] 哪个是有序的。
            // 对于这种情况，我们只能将当前二分区间的左边界加一，右边界减一，然后在新区间上继续二分查找。
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            } else if (nums[left] <= nums[mid]) {  // 左边有序
                if (nums[left] <= target && target < nums[mid]) {  // target的值在左半边
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

        return false;
    }
}

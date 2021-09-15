package pub.zues.studies;

// https://leetcode-cn.com/problems/find-peak-element/

class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int left = 0, right = n - 1, result = -1;

        if (n == 1) {
            return 0;
        }

        while (left <= right) {
            int mid = (left + right) / 2;
            // {1,3} {2,1}
            if (mid == 0) {
                result = nums[0] > nums[1] ? 0 : 1;
                break;
            }

            if (mid == n - 1) {
                result = nums[n - 1] > nums[n - 2] ? n - 1 : n - 2;
                break;
            }

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                result = mid;
                break;
            }

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }

        return result;
    }
}

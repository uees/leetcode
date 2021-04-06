package pub.zues.studies;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int[] nums1 = new int[]{1,2,3,0,0,0};
        int[] nums2 = {2,5,6};

        Solution solution = new Solution();
        solution.merge(nums1, 3, nums2, 3);

        System.out.println(Arrays.toString(nums1));  // [1,2,2,3,5,6]
    }
}

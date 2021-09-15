package pub.zues.studies;

public class Main {
    public static void main(String[] args) {
        var s = new Solution();
        int[] nums;

        nums = new int[]{1, 2, 3, 1};
        System.out.println("[1,2,3,1], " + s.findPeakElement(nums));

        nums = new int[]{1, 2, 1, 3, 5, 6, 4};
        System.out.println("[1,2,1,3,5,6,4], " + s.findPeakElement(nums));

        nums = new int[]{1, 2, 3, 4, 5};
        System.out.println("[1,2,3,4,5], " + s.findPeakElement(nums));

        nums = new int[]{3, 2, 1};
        System.out.println("[3,2,1], " + s.findPeakElement(nums));
    }
}

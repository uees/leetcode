package pub.zues.studies;

/**
 * 给你一个整数数组 arr ，数组中的每个整数 互不相同 。另有一个由整数数组构成的数组 pieces，其中的整数也 互不相同 。请你以 任意顺序 连接 pieces 中的数组以形成 arr 。但是，不允许 对每个数组 pieces[i] 中的整数重新排序。
 * <p>
 * 如果可以连接 pieces 中的数组形成 arr ，返回 true ；否则，返回 false 。
 * <p>
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/check-array-formation-through-concatenation
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

public class Main {

    public static void main(String[] args) {
        int[] arr = {15, 88};
        int[][] pieces = {{88}, {15}};

        Solution solution = new Solution();
        assert solution.canFormArray(arr, pieces) : "测试失败";

        assert !solution.canFormArray(new int[]{49, 18, 16}, new int[][]{{16, 18, 49}}) : "测试失败";
    }
}

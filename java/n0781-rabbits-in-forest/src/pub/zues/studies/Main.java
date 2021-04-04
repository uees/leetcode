package pub.zues.studies;

/**
 * 森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在 answers 数组里。
 * <p>
 * 返回森林中兔子的最少数量。
 * <p>
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/rabbits-in-forest
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

public class Main {

    public static void main(String[] args) {
        int[] answers;
        answers = new int[]{1, 1, 2};

        Solution solution = new Solution();
        assert solution.numRabbits(answers) == 5;

        answers = new int[]{10, 10, 10};
        assert solution.numRabbits(answers) == 11;

        answers = new int[]{};
        assert solution.numRabbits(answers) == 0;
    }
}

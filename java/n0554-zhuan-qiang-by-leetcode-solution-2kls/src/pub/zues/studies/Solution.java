package pub.zues.studies;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 问题可以转换成求「垂线穿过的砖块边缘数量的最大值」，用砖墙的高度减去该最大值即为答案。
 *
 * 注意到题目要求垂线不能通过砖墙的两个垂直边缘，所以砖墙两侧的边缘不应当被统计。因此，我们只需要统计每行砖块中除了最右侧的砖块以外的其他砖块的右边缘即可。
 */

public class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        // 构建一个 hashmap, 其中键为砖至左边的宽度, 值为符合这个宽度的行数
        Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (List<Integer> widths : wall) {
            int n = widths.size();
            int sum = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += widths.get(i);
                cnt.put(sum, cnt.getOrDefault(sum, 0) + 1);
            }
        }
        int maxCnt = 0;
        for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
            maxCnt = Math.max(maxCnt, entry.getValue());
        }
        return wall.size() - maxCnt;
    }
}

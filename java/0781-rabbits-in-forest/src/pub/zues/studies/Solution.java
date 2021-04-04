package pub.zues.studies;

import java.util.HashMap;
import java.util.Map;

/**
 * 分析：
 * 两只相同颜色的兔子看到的其他同色兔子数必然是相同的。反之，若两只兔子看到的其他同色兔子数不同，那么这两只兔子颜色也不同。
 * 因此，将 answers 中值相同的元素分为一组，对于每一组，计算出兔子的最少数量，然后将所有组的计算结果累加，就是最终的答案。
 * <p>
 * 如果 7 只兔子都回答 3，假如其中一只为 red，那么一定有 3+1=4 只red. 假设剩余的还有一只为 blue, 那么还有4只blue,
 * 要保证最小化原则，这8只兔子只有一只没包含在列表。 兔子数量最少为8只。
 * <p>
 * 一般的， 对 x 只兔子都回答 y, 那么颜色数量为 x / (y+1), 有余数则为商+1种颜色。每种颜色兔子数量为 y+1
 */
public class Solution {
    public int numRabbits(int[] answers) {
        // 用哈希表统计 answers 中各个元素的出现次数
        Map<Integer, Integer> count = new HashMap<>();
        for (int y : answers) {
            count.put(y, count.getOrDefault(y, 0) + 1);
        }

        int sum = 0;
        // 同时遍历key和value可以使用for each循环遍历Map对象的entrySet()集合
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            int y = entry.getKey(), x = entry.getValue();
            int color;
            // 如果整除
            if (x % (y + 1) == 0) {
                color = x / (y + 1);
            } else {
                color = x / (y + 1) + 1;
            }
            sum += color * (y + 1);
        }

        return sum;
    }
}

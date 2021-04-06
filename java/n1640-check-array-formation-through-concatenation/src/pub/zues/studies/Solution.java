package pub.zues.studies;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        // 用一个 Map 保存 pieces 便于查找
        Map<Integer, int[]> store = new HashMap<>();
        for (int[] piece : pieces) {
            store.put(piece[0], piece);
        }

        // 遍历 arr 开始判断逻辑
        for (int i = 0; i < arr.length; ) {
            if (!store.containsKey(arr[i])) {
                return false;
            }

            int[] piece = store.get(arr[i]);
            for (int value : piece) {
                if (value != arr[i]) {
                    return false;
                }

                i++;
            }
        }

        return true;
    }
}

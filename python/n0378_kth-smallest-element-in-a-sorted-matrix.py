"""
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。



示例：

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
```

提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

from itertools import chain


def kthSmallest(matrix: list, k: int) -> int:
    # 二维转一维
    temp = list(chain.from_iterable(matrix))
    # 排序
    temp.sort()
    return temp[k-1]


if __name__ == "__main__":
    assert kthSmallest([[1, 5, 9], [10, 11, 13], [12, 13, 15]], 8) == 13, "不相等"

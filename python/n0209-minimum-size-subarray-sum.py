'''
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例:

```
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''


class Solution:
    def minSubArrayLen(self, s: int, nums: list) -> int:
        """双指针 O(n) 时间复杂度"""
        left = 0
        cursum = 0
        mincount = float('inf')  # 正无穷

        for right in range(len(nums)):
            cursum += nums[right]

            while cursum >= s:
                mincount = min(mincount, right-left+1)
                cursum = cursum-nums[left]
                left += 1

        return mincount if mincount != float('inf') else 0


if __name__ == "__main__":
    s = Solution()
    print(s.minSubArrayLen(s=7, nums=[2, 3, 1, 2, 4, 3]))

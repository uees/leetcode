"""
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )


示例 1：

```
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
```

示例 2：

```
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

提示：

    1 <= values <= 10000
    最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()


class CQueue:

    def __init__(self):
        # 用两个栈实现一个队列
        self._stack_in = []
        self._stack_sout = []

    def appendTail(self, value: int) -> None:
        self._stack_in.append(value)

    def deleteHead(self) -> int:
        if not self._stack_sout:
            while self._stack_in:
                self._stack_sout.append(self._stack_in.pop())

        return self._stack_sout.pop() if self._stack_sout else -1


def run(input1, input2):
    result = []
    obj = CQueue()
    for index, method in enumerate(input1):
        if method == "deleteHead":
            result.append(obj.deleteHead())
        elif method == "appendTail":
            result.append(obj.appendTail(input2[index][0]))
        else:
            result.append(None)
    return result


if __name__ == "__main__":
    input1 = ["CQueue", "deleteHead", "appendTail", "appendTail", "deleteHead", "deleteHead"]
    input2 = [[], [], [5], [2], [], []]
    print(run(input1, input2))

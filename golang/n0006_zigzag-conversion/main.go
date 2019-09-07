package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	fmt.Println(convert("LEETCODEISHIRING", 3)) // LCIRETOESIIGEDHN
	fmt.Println(convert("LEETCODEISHIRING", 4)) // LDREOEIIECIHNTSG
}

// 官方解法1
// 我们可以使用 min(numRows,len(s)) 来表示 Z 字形图案中的非空行。
// 从左到右迭代 s，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
// 只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。
func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}

	maxRow := int(math.Min(float64(numRows), float64(len(s))))
	rows := make([]string, maxRow)
	curRow := 0
	goingDown := false

	for i := range s {
		rows[curRow] += s[i : i+1]
		if curRow == 0 || curRow == numRows-1 {
			goingDown = !goingDown
		}
		if goingDown {
			curRow++
		} else {
			curRow--
		}
	}

	return strings.Join(rows, "")
}

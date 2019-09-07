package main

import "fmt"

type myInt int64

func (x *myInt) pop() myInt {
	remainder := *x % 10 // 余数
	*x = *x / 10         // 商

	return remainder
}

func (x *myInt) append(y myInt) {
	*x = *x*10 + y
}

func main() {
	fmt.Println(reverse(123))        // 321
	fmt.Println(reverse(-123))       // -321
	fmt.Println(reverse(120))        // 21
	fmt.Println(reverse(1534236469)) // 9646324351 溢出 应该为 0
}

// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
func reverse(x int) int {
	var result, remainder myInt
	var _x = myInt(x)
	for {
		if _x != 0 {
			remainder = _x.pop()
			result.append(remainder)
		} else {
			break
		}
	}

	// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。
	// 请根据这个假设，如果反转后整数溢出那么就返回 0。
	resultInt := int(result)
	if int(int32(result)) != resultInt {
		return 0
	}

	return resultInt
}

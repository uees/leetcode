package main

import "fmt"

// 假设我们的环境只能存储得下 32 位的有符号整数
type myInt int32

const maxInt = myInt((1 << 31) - 1)
const minInt = myInt(-(1 << 31))

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
	var result, pop myInt
	var _x = myInt(x)
	a := maxInt / 10
	b := minInt / 10
	m := maxInt % 10 // 7
	n := minInt % 10 // -8
	for _x != 0 {
		pop = _x.pop()
		// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。
		// 请根据这个假设，如果反转后整数溢出那么就返回 0。
		if result > a || (result == a && pop > m) {
			return 0
		}
		if result < b || (result == b && pop < n) {
			return 0
		}
		result.append(pop)
	}

	/**
	resultInt := int(result)
	if int(int32(result)) != resultInt {
		return 0
	}
	return resultInt
	*/

	return int(result)
}

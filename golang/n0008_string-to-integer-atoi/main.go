package main

import (
	"fmt"
	"strings"
)

// int32 最大整数
const intMax = (1 << 31) - 1

// int32 最小整数
const intMin = -(1 << 31)

const intMaxDiv10 = intMax / 10
const intMinDiv10 = intMin / 10
const intMaxMod10 = intMax % 10 // 7
const intMinMod10 = intMin % 10 // -8

var mapInt = func() map[rune]int {
	var result = make(map[rune]int)
	for i, c := range "0123456789" {
		result[c] = i
	}
	return result
}()

func main() {
	// fmt.Println(myAtoi("4193 with words"))
	fmt.Println(myAtoi("       -4193 with words"))
}

// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
// 当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
// 该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
// 在任何情况下，若函数不能进行有效的转换时，请返回 0。
// 假设我们的环境只能存储 32 位大小的有符号整数, 如果数值超过这个范围，请返回  INT_MAX 或 INT_MIN
func myAtoi(str string) int {
	result := 0
	sign := 1
	str = strings.TrimSpace(str)
	if len(str) == 0 {
		return 0
	}
	if str[:1] == "+" || str[:1] == "-" {
		if str[:1] == "-" {
			sign = -1
		}
		str = str[1:]
	}
	for _, c := range str {
		if _, ok := mapInt[c]; !ok {
			break
		}
		if result > intMaxDiv10 || (result == intMaxDiv10 && sign*mapInt[c] > intMaxMod10) {
			return intMax
		}
		if result < intMinDiv10 || (result == intMinDiv10 && sign*mapInt[c] < intMinMod10) {
			return intMin
		}
		result = result*10 + sign*mapInt[c]
	}

	return result
}

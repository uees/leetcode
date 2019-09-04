package main

import "fmt"

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9
	fmt.Println(twoSum(nums, target))
}

func twoSum(nums []int, target int) []int {
	temp := make(map[int]int)
	result := make([]int, 2)
	var diff int
	for i, v := range nums {
		if temp[v] != 0 {
			result[0] = temp[v] - 1
			result[1] = i
		}
		diff = target - v
		temp[diff] = i + 1 // golang int 类型默认为 0，防止与切片的第1位下标冲突
	}
	return result
}

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(minSubArrayLen(7, []int{2, 3, 1, 2, 4, 3}))
}

func minSubArrayLen(s int, nums []int) int {
	left, right, cursum := 0, 0, 0
	mincount := math.MaxInt32

	min := func(x, y int) int {
		if x < y {
			return x
		}
		return y
	}

	for right < len(nums) {
		cursum += nums[right]
		for cursum >= s {
			mincount = min(mincount, right-left+1)
			cursum -= nums[left]
			left++
		}
		right++
	}

	if mincount == math.MaxInt32 {
		return 0
	}

	return mincount
}

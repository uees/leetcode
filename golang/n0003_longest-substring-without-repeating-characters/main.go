package main

import "fmt"

func main() {
	s := "abcabcbb"
	fmt.Println(lengthOfLongestSubstring(s)) // 3
}

func lengthOfLongestSubstring(s string) int {
	charLastPos := make(map[rune]int)
	var len, maxLen int
	for i, c := range s {
		if charLastPos[c] == 0 {
			len++
		} else {
			if i-(charLastPos[c]-1) > len {
				len++
			} else {
				len = i - (charLastPos[c] - 1)
			}
		}

		if len > maxLen {
			maxLen = len
		}

		charLastPos[c] = i + 1
	}

	return maxLen
}

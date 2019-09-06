package main

import "fmt"

func main() {
	fmt.Println(longestPalindrome("babad"))
	fmt.Println(longestPalindrome(""))
	fmt.Println(longestPalindrome("a"))
	fmt.Println(longestPalindrome("ab"))
	fmt.Println(longestPalindrome("abc"))
}

// 我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n−1 个这样的中心。
// 奇数回文中心位于字符上，偶数回文中心位于两个字母之间，所以共有 2n−1 个这样的中心
func longestPalindrome(s string) string {
	var maxLen int
	var maxPalindrome string

	for index := range s {
		for _, isOdd := range []bool{false, true} {
			palindrome, len := getMaxPalindrome(s, index, isOdd)
			if len > maxLen {
				maxLen = len
				maxPalindrome = palindrome
			}
		}
	}

	return maxPalindrome
}

// isOdd 是否奇数回文字符串
func getMaxPalindrome(s string, index int, isOdd bool) (string, int) {
	var palindrome string
	var palindromeLen, left, right int

	left = index
	if isOdd {
		palindrome = s[index : index+1]
		palindromeLen = 1
		right = index
	} else {
		palindromeLen = 0
		right = index - 1
	}

	length := len(s)
	for i := 0; i < length; i++ {
		left--
		if left < 0 {
			break
		}
		right++
		if right > length-1 {
			break
		}
		if s[left] != s[right] {
			break
		}
		palindromeLen += 2
		palindrome = s[left : right+1]
	}
	return palindrome, palindromeLen
}

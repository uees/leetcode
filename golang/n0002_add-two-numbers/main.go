package main

import (
	"fmt"
)

// ListNode Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	l1 := createListNode(123)
	l2 := createListNode(987)
	l3 := addTwoNumbers(l1, l2)
	display(l3)
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	p1, p2 := l1, l2
	result := new(ListNode)
	p3 := result
	// count 处理进位
	// sum 求和
	var count, sum int
	for p1 != nil || p2 != nil {
		if p1 == nil {
			sum = count + p2.Val
			p2 = p2.Next
		} else if p2 == nil {
			sum = count + p1.Val
			p1 = p1.Next
		} else {
			sum = count + p1.Val + p2.Val
			p1 = p1.Next
			p2 = p2.Next
		}

		if sum > 9 {
			sum -= 10
			count = 1
		} else {
			count = 0
		}

		p3.Next = new(ListNode)
		p3 = p3.Next
		p3.Val = sum
	}

	// 处理最后的进位
	if count == 1 {
		p3.Next = new(ListNode)
		p3 = p3.Next
		p3.Val = count
	}

	return result.Next
}

func createListNode(val int) *ListNode {
	result := new(ListNode)
	p := result
	for val != 0 {
		p.Val = val % 10
		val = val / 10
		p.Next = new(ListNode)
		p = p.Next
	}

	return result
}

func display(ln *ListNode) {
	var sum = 0
	var factor = 1
	for ln != nil {
		sum += ln.Val * factor
		factor *= 10
		ln = ln.Next
	}

	fmt.Println(sum)
}

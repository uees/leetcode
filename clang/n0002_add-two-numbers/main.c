#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2. 两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

// 解题思路:
// 分别获取两个链表的长度
// 两个链表共有长度的部分依次相加，注意处理进位问题，如果最高位计算时还产生进位，则还需要添加一个额外结点
// 返回新的链表

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    // result 用于返回
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    // p 用于纸箱 result 链表中的当前节点
    struct ListNode *p = result;
    // p1 和 p2 分别指向 l1 和 l2 链表中的当前节点
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    // sum 用来判断是否需要进位, 如果需要进位sum自减10, count 值 1 用于和下一位相加
    int count = 0, sum = 0;
    while (p1 != NULL || p2 != NULL)
    {
        if (p1 != NULL && p2 != NULL)
        {
            sum = p1->val + p2->val + count;

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1 != NULL)
        {
            sum = p1->val + count;

            p1 = p1->next;
        }
        else
        {
            sum = p2->val + count;

            p2 = p2->next;
        }

        // 判断是否进位
        if (sum > 9)
        {
            sum -= 10;
            count = 1;
        }
        else
        {
            count = 0;
        }

        // 从第二节点开始存值
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = sum;
    }

    // 判断最后一位是否需要进位
    if (count)
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = count;
    }

    // 返回链表的尾节点
    p->next = NULL;
    p = result;
    result = result->next; // 跳过第一个 NULL 节点

    free(p);

    return result;
}

static struct ListNode *node_build(const char *digits)
{
    struct ListNode *res, *p, *prev;
    int first = 1;
    int len = strlen(digits);
    const char *c = digits + len - 1;
    prev = NULL;
    while (len-- > 0)
    {
        p = malloc(sizeof(*p));
        if (first)
        {
            first = 0;
            res = p;
        }
        p->val = *c-- - '0';
        p->next = NULL;
        if (prev != NULL)
        {
            prev->next = p;
        }
        prev = p;
    }

    return res;
}

static void show(struct ListNode *ln)
{
    int sum = 0, factor = 1;
    while (ln != NULL)
    {
        sum += ln->val * factor;
        factor *= 10;
        ln = ln->next;
    }
    printf("%d\n", sum);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: ./test n1 n2\n");
        exit(-1);
    }

    struct ListNode *l1 = node_build(argv[1]);
    struct ListNode *l2 = node_build(argv[2]);
    struct ListNode *res = addTwoNumbers(l1, l2);
    show(l1);
    show(l2);
    show(res);

    return 0;
}

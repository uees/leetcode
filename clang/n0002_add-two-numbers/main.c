#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2. �������

�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
*/

// ����˼·:
// �ֱ��ȡ��������ĳ���
// ���������г��ȵĲ���������ӣ�ע�⴦���λ���⣬������λ����ʱ��������λ������Ҫ���һ��������
// �����µ�����

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
    // result ���ڷ���
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    // p ����ֽ�� result �����еĵ�ǰ�ڵ�
    struct ListNode *p = result;
    // p1 �� p2 �ֱ�ָ�� l1 �� l2 �����еĵ�ǰ�ڵ�
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    // sum �����ж��Ƿ���Ҫ��λ, �����Ҫ��λsum�Լ�10, count ֵ 1 ���ں���һλ���
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

        // �ж��Ƿ��λ
        if (sum > 9)
        {
            sum -= 10;
            count = 1;
        }
        else
        {
            count = 0;
        }

        // �ӵڶ��ڵ㿪ʼ��ֵ
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = sum;
    }

    // �ж����һλ�Ƿ���Ҫ��λ
    if (count)
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = count;
    }

    // ���������β�ڵ�
    p->next = NULL;
    p = result;
    result = result->next; // ������һ�� NULL �ڵ�

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

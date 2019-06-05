#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// abccba
static int lengthOfLongestSubstring(char *s)
{
    int offset[128]; // 记录字符在 s 中最后一次出现的位置
    int max_len = 0;
    int len = 0;
    int index = 0; // 字符串 s 的下标索引

    memset(offset, 0xff, sizeof(offset));
    for (unsigned char uc; *s != '\0'; s++, index++)
    {
        // 0xff 其中一号位为符号位，为1，则说明为负数
        // 1111 1111 按位取反 1000 0000, 再加1 ——> 1000 0001
        // 所以 char b = 0xff 转为 int 类型结果为 -1
        uc = *s;

        if (offset[uc] == -1)
        {
            len++;
        }
        else
        {
            if (index - offset[uc] > len)
            {
                len++;
            }
            else
            {
                len = index - offset[uc];
            }
        }

        if (len > max_len)
        {
            max_len = len;
        }

        // 记录位置
        offset[uc] = index;
    }

    return max_len;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./main string\n");
        exit(-1);
    }

    printf("%d\n", lengthOfLongestSubstring(argv[1]));

    return 0;
}

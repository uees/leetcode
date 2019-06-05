#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// abccba
static int lengthOfLongestSubstring(char *s)
{
    int offset[128]; // ��¼�ַ��� s �����һ�γ��ֵ�λ��
    int max_len = 0;
    int len = 0;
    int index = 0; // �ַ��� s ���±�����

    memset(offset, 0xff, sizeof(offset));
    for (unsigned char uc; *s != '\0'; s++, index++)
    {
        // 0xff ����һ��λΪ����λ��Ϊ1����˵��Ϊ����
        // 1111 1111 ��λȡ�� 1000 0000, �ټ�1 ����> 1000 0001
        // ���� char b = 0xff תΪ int ���ͽ��Ϊ -1
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

        // ��¼λ��
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

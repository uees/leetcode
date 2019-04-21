#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
int main(int argc, char **argv)
{

    struct hash_table *t = create_hash_table(1024); //1024������

    hash_insert(t, "xiaoming", (void *)12);
    hash_insert(t, "xiaohong", (void *)36);
    hash_insert(t, "xiaowang", (void *)"������xxxx��");

    int ret = (int)hash_find(t, "xiaoming"); //����hash��key����Ӧ��value
    printf("xiaoming = > %d\n", ret);

    char *address = hash_find(t, "xiaowang"); //����hash��key����Ӧ��value
    printf("address = > %s\n", address);

    void *value = hash_find(t, "tttttttt"); //����hash��key����Ӧ��value
    if (value == NULL)
    {
        printf("�Ҳ���ֵ -�� %s\n", value);
    }

    hash_delete(t, "xiaoming"); //ɾ��

    value = hash_find(t, "xiaoming");
    if (value == NULL)
    {
        printf("���Ҳ��� ��Ϊ 'xiaoming' ��ֵ %s\n", value);
    }

    destroy_hash_table(t); //ɾ������

    system("pause");
    return 0;
}

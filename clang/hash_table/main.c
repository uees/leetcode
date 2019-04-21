#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
int main(int argc, char **argv)
{

    struct hash_table *t = create_hash_table(1024); //1024个集合

    hash_insert(t, "xiaoming", (void *)12);
    hash_insert(t, "xiaohong", (void *)36);
    hash_insert(t, "xiaowang", (void *)"北京市xxxx区");

    int ret = (int)hash_find(t, "xiaoming"); //查找hash表key，对应的value
    printf("xiaoming = > %d\n", ret);

    char *address = hash_find(t, "xiaowang"); //查找hash表key，对应的value
    printf("address = > %s\n", address);

    void *value = hash_find(t, "tttttttt"); //查找hash表key，对应的value
    if (value == NULL)
    {
        printf("找不到值 -》 %s\n", value);
    }

    hash_delete(t, "xiaoming"); //删除

    value = hash_find(t, "xiaoming");
    if (value == NULL)
    {
        printf("查找不到 键为 'xiaoming' 的值 %s\n", value);
    }

    destroy_hash_table(t); //删除对象

    system("pause");
    return 0;
}

#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

struct hash_table; //hash�ṹ

// ����hash����                n:���ٸ�����
struct hash_table *create_hash_table(int n);

//����һ��key:value,���ж��Ƿ��ظ�
void hash_insert(struct hash_table *t, char *key, void *value);

//��hash������������ǵ�ֵ
void *hash_find(struct hash_table *t, char *key);

//ɾ��hash��
void hash_delete(struct hash_table *t, char *key);

//����/�޸�key:value
void hash_set(struct hash_table *t, char *key, void *value);

//�������е�hash �������
void hash_clear(struct hash_table *t);

//ɾ��hash����
void destroy_hash_table(struct hash_table *t);

#endif // !__HASH_TABLE_H__

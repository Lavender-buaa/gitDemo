#include <stdio.h>
#include <stdlib.h>

typedef struct doubleList
{
    int data;
    struct doubleList *left;
    struct doubleList *right;
} DouList;
void bubble_sort(int *array, int n);       // 排序函数
void add(DouList *header, int data);       // 表尾添加函数
DouList *init_list(int n);                 // 初始化指定长度的表
void output(DouList *header);              // 输出表的信息82（正序and倒序输出检验是是否满足双向且循环）
DouList *set_order_list();                 // 以指定元素建立一个递增表
void setify(DouList **header);             // 集合化链表
int isInList(DouList *, int);              // 判断元素是否在链表中
void del_value(DouList *header, int data); // 删除所有指定元素

DouList *init_list(int n)
{
    DouList *header = (DouList *)malloc(sizeof(DouList));
    DouList *p = header;
    header->left = header;
    header->right = header;
    for (int i = 0; i < n; i++)
    {
        DouList *newNode = (DouList *)malloc(sizeof(DouList));
        p->right = newNode;
        newNode->data = 0;
        newNode->left = p;
        newNode->right = header;
        p = p->right;
        header->left = newNode;
    }
    header->data = n;
    return header;
}

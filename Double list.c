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

void add(DouList *header, int data)
{
    DouList *p = (DouList *)malloc(sizeof(DouList));
    p = header->left;
    DouList *newNode = (DouList *)malloc(sizeof(DouList));
    newNode->right = header;
    newNode->left = p;
    p->right = newNode;
    header->left = newNode;
    newNode->data = data;
    header->data++;
}

void output(DouList *header)
{
    printf("The length of double list is %d\n", header->data);
    printf("The data are:\n");
    DouList *p = header->right;
    for (int i = 0; i < header->data * 2 + 1; i++)
    {
        printf("%-3d", p->data);
        p = p->right;
    }
    printf("\n");

    p = p->left;
    for (int i = 0; i < header->data * 2 + 1; i++)
    {
        printf("%-3d", p->data);
        p = p->left;
    }
    printf("\n");
}

DouList *set_order_list()
{
    int array[20] = {0};
    DouList *header = init_list(0);
    printf("Please enter the number of data you want:");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    buuble_sort(array, n);
    for (int i = 0; i < n; i++)
    {
        add(header, array[i]);
    }
    return header;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct doubleList
{
    int data;
    struct doubleList *left;
    struct doubleList *right;
} DouList;
void bubble_sort(int *array, int n);       // ������
void add(DouList *header, int data);       // ��β��Ӻ���
DouList *init_list(int n);                 // ��ʼ��ָ�����ȵı�
void output(DouList *header);              // ��������Ϣ82������and��������������Ƿ�����˫����ѭ����
DouList *set_order_list();                 // ��ָ��Ԫ�ؽ���һ��������
void setify(DouList **header);             // ���ϻ�����
int isInList(DouList *, int);              // �ж�Ԫ���Ƿ���������
void del_value(DouList *header, int data); // ɾ������ָ��Ԫ��

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

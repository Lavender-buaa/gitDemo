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

#include <cstdio>
#include <malloc.h>
#include <iostream>

using namespace std;

/* �����������͵Ķ��� */
typedef struct node
{
	int data;           /* int�͵Ľ�������� */
	struct node* next;  /* ����ָ���� */
}node, *LinkList;

/* ������ĳ�ʼ�� */
LinkList LinkListInit()
{
	node* L;
	L = (node*)malloc(sizeof(node));
	if (L == NULL)
	{
		cout << "�����ڴ�ռ�ʧ�ܣ�" << endl;
	}
	L->next = NULL;
	return L;
}

/* �������� */
LinkList LinkListCreat()
{
	node* L;
	L = (node*)malloc(sizeof(node));
	L->next = NULL;
    int num;
    while (cin>>num)
    {
		node* p;
        p = (node*)malloc(sizeof(node));
        p->data = num;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

/* ���ң��ڱ��в��ҵ�k��Ԫ�أ����ҵ����ظ�Ԫ��ָ�룬���߷��ؿ�ָ��NULL */
LinkList Find_List(LinkList L, int k)  /* LΪ��ͷ��㵥�����ͷָ�� */
{
	LinkList p;
	int i;
	i = 1;               /* ������ */
	p = L->next;         /* ָ���һ��Ԫ�ؽ�� */
	while (p && i < k)   /* ����ֱ��pָ���k��Ԫ�ؽ���pΪ��ָ�� */
	{
		p = p->next;
		i++;
	}
	if (p && i == k)    /* ���ڵ�k��Ԫ����ָ��pָ���Ԫ�ؽ�� */
	{
		return p;
	}
	return NULL;
}

/* ���룺��Ԫ��newElem���뵽���е�k��Ԫ��֮ǰ�����ɹ��򷵻�0�����߷���-1 */
int Insert_List(LinkList L, int k, int newElem)
{
	LinkList p, s;
	if (k == 1) p = L;
	else p = Find_List(L, k - 1);
	if (!p) return -1;
	s = (node*)malloc(sizeof(node));  /* ������Ԫ�صĽ��ռ� */
	if (!s) return -1;
	s->data = newElem;
	s->next = p->next;
	p->next = s;
	return 0;
}

/* ɾ����ɾ�����е�k��Ԫ�ؽ�㣬���ɹ��򷵻�0�����߷���-1 */
int Delete_List(LinkList L, int k)
{
	LinkList p, q;
	if (k == 1) p = L;              /* ɾ����һ��Ԫ�ؽ�� */
	else p = Find_List(L, k - 1);   /* ���ҵ�k-1��Ԫ�ز���pָ���Ԫ�ؽ��*/
	if (!p || !p->next) return -1;  /* ���в����ڵ�k��Ԫ�� */
	q = p->next;                    /* ��qָ���k��Ԫ�ؽ�� */
	p->next = q->next;              
	free(q);                        /* ɾ���ڵ� */
	return 0;
}
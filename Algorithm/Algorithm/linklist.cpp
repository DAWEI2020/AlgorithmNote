#include <cstdio>
#include <stdio.h>

/* �����������͵Ķ��� */
typedef struct node
{
	int data;           /* int�͵Ľ�������� */
	struct node* next;  /* ����ָ���� */
}NODE, *LinkList;

/* �ڱ��в��ҵ�k��Ԫ�أ����ҵ����ظ�Ԫ��ָ�룬���߷��ؿ�ָ��NULL */
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

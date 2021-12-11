#include <cstdio>
#include <stdio.h>

/* 单链表结点类型的定义 */
typedef struct node
{
	int data;           /* int型的结点数据域 */
	struct node* next;  /* 结点的指针域 */
}NODE, *LinkList;

/* 在表中查找第k个元素，若找到返回该元素指针，否者返回空指针NULL */
LinkList Find_List(LinkList L, int k)  /* L为带头结点单链表的头指针 */
{
	LinkList p;
	int i;
	i = 1;               /* 计数器 */
	p = L->next;         /* 指向第一个元素结点 */
	while (p && i < k)   /* 查找直到p指向第k个元素结点或p为空指针 */
	{
		p = p->next;
		i++;
	}
	if (p && i == k)    /* 存在第k个元素且指针p指向该元素结点 */
	{
		return p;
	}
	return NULL;
}

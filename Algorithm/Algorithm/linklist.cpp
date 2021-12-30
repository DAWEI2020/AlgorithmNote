#include <cstdio>
#include <malloc.h>
#include <iostream>

using namespace std;

/* 单链表结点类型的定义 */
typedef struct node
{
	int data;           /* int型的结点数据域 */
	struct node* next;  /* 结点的指针域 */
}node, *LinkList;

/* 单链表的初始化 */
LinkList LinkListInit()
{
	node* L;
	L = (node*)malloc(sizeof(node));
	if (L == NULL)
	{
		cout << "申请内存空间失败！" << endl;
	}
	L->next = NULL;
	return L;
}

/* 单链表创建 */
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

/* 查找：在表中查找第k个元素，若找到返回该元素指针，否者返回空指针NULL */
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

/* 插入：将元素newElem插入到表中第k个元素之前，若成功则返回0，否者返回-1 */
int Insert_List(LinkList L, int k, int newElem)
{
	LinkList p, s;
	if (k == 1) p = L;
	else p = Find_List(L, k - 1);
	if (!p) return -1;
	s = (node*)malloc(sizeof(node));  /* 创建新元素的结点空间 */
	if (!s) return -1;
	s->data = newElem;
	s->next = p->next;
	p->next = s;
	return 0;
}

/* 删除：删除表中第k个元素结点，若成功则返回0，否者返回-1 */
int Delete_List(LinkList L, int k)
{
	LinkList p, q;
	if (k == 1) p = L;              /* 删除第一个元素结点 */
	else p = Find_List(L, k - 1);   /* 查找第k-1个元素并令p指向该元素结点*/
	if (!p || !p->next) return -1;  /* 表中不存在第k个元素 */
	q = p->next;                    /* 令q指向第k个元素结点 */
	p->next = q->next;              
	free(q);                        /* 删除节点 */
	return 0;
}
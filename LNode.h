#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ERROR  0
#define TRUE 1
#define FALSE 0
#define OK 1
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;


//逆位序输入n个元素的值，建立带表头结点的单链表L
void CreateList_L(LinkList L, int n) {
	//先建立一个带头结点的单链表
	L->next = NULL;
	for (int i = n; i > 0; --i)
	{
		LNode *p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
	printf("链表创建成功！\n");
}

//查找链表中第i个元素
Status GetElem_L(LinkList L, int i, int *e) {
	//当第i个元素存在时候，其赋值给e并返回OK，否则ERROR
	LinkList p = L->next;
	int j = 1;
	while (p &&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//在带头结点的单链表L中第i个位置之前插入元素e
Status ListInsert_L(LinkList L, int i, int e) {
	LinkList p = L;
	int j = 0;
	//寻找第i-1个结点
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		return ERROR;
	}
	//生成新结点
	LinkList s = (LinkList)malloc(sizeof(LNode));
	//插入L中
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("%d插入成功！\n", e);
	return OK;
}

//在带头结点的单链表L中删除第i个元素，并由e返回其值
Status ListDelte_L(LinkList L, int i, int *e) {
	LinkList p = L;
	int j = 0;
	//寻找第i个结点，并令p指向其前趋
	while (p->next&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	//删除位置不合理
	if (!(p->next) || j > i - 1)
	{
		return ERROR;
	}
	//删除并释放结点
	LinkList q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

//归并La和Lb得到一个新的单链表LC
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc) {
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc = La;
	*Lc = pc;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;			//用La的头结点作为Lc的头结点	
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	//插入剩余段
	pc->next = pa ? pa : pb;
	//释放Lb的头结点
	free(Lb);
}

//打印链表
void printAll(LinkList L) {
	LinkList p = L->next;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
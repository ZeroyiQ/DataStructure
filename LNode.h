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


//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
void CreateList_L(LinkList L, int n) {
	//�Ƚ���һ����ͷ���ĵ�����
	L->next = NULL;
	for (int i = n; i > 0; --i)
	{
		LNode *p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
	printf("�������ɹ���\n");
}

//���������е�i��Ԫ��
Status GetElem_L(LinkList L, int i, int *e) {
	//����i��Ԫ�ش���ʱ���丳ֵ��e������OK������ERROR
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

//�ڴ�ͷ���ĵ�����L�е�i��λ��֮ǰ����Ԫ��e
Status ListInsert_L(LinkList L, int i, int e) {
	LinkList p = L;
	int j = 0;
	//Ѱ�ҵ�i-1�����
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		return ERROR;
	}
	//�����½��
	LinkList s = (LinkList)malloc(sizeof(LNode));
	//����L��
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("%d����ɹ���\n", e);
	return OK;
}

//�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelte_L(LinkList L, int i, int *e) {
	LinkList p = L;
	int j = 0;
	//Ѱ�ҵ�i����㣬����pָ����ǰ��
	while (p->next&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	//ɾ��λ�ò�����
	if (!(p->next) || j > i - 1)
	{
		return ERROR;
	}
	//ɾ�����ͷŽ��
	LinkList q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

//�鲢La��Lb�õ�һ���µĵ�����LC
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc) {
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc = La;
	*Lc = pc;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;			//��La��ͷ�����ΪLc��ͷ���	
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	//����ʣ���
	pc->next = pa ? pa : pb;
	//�ͷ�Lb��ͷ���
	free(Lb);
}

//��ӡ����
void printAll(LinkList L) {
	LinkList p = L->next;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
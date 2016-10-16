#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
typedef struct  Node
{
	int num, code;
	struct Node *next;
}LNode, *LinkList;

//����������joseph ring��
LNode *Create_Joseph(LinkList L, int n)
{
	int i, key;
	LNode *p, *s;
	p = L;
	for (i = 1;i <= n;i++)
	{
		printf("��%d�˵�����:", i);
		scanf("%d", &key);
		s = (LNode *)malloc(sizeof(LNode));
		p->next = s;
		p = s;
		p->num = i;
		p->code = key;
	}
	p->next = L->next;
	p = L;
	L = L->next;
	free(p);
	return L;
}

//���
void Output_Joseph(LinkList L, int m, int n)
{
	int i, j, key;
	LNode *p, *s;
	key = m;
	do {
		p = L;
		j = 1;
		if (key == 1)			//����keyΪ1ʱ
		{
			i = p->num;
			key = p->code;
			printf("��%d��", i);
			s = p->next;
			while (s->next != L) {
				s = s->next;
			}
			s->next = p->next;
			L = p->next;
			free(p);
			n--;
		}
		else
		{
			while (j<key)
			{
				s = p;
				p = p->next;
				j++;
			}
			i = p->num;
			key = p->code;
			printf("��%d��", i);
			s->next = p->next;
			L = p->next;
			free(p);
			n--;
		}
	} while (n>0);
}

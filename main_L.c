#include<stdio.h>	
#include"LNode.h"
int main() {

	//-----��֤����-----
	printf("-----��֤����-----\n");
	//1)��������
	LinkList head = (LinkList)malloc(sizeof(LNode));
	CreateList_L(head, 5);
	printAll(head);
	printf("\n");

	//2)����һЩԪ��: 10 23 ��֤��ListInsert_L����
	printf("����һЩԪ��: 10,23 \n");
	ListInsert_L(head, 2, 10);
	ListInsert_L(head, 3, 23);
	printAll(head);
	printf("\n");

	//3)ɾ���ڶ����� ��֤��ListDelte_L����
	printf("ɾ���ڶ�����\n");
	int e=0;
	if (ListDelte_L(head, 2, &e))
	{
		printf("ɾ��%d�ɹ���\n",e); 
		printAll(head);
		printf("\n");
	}
	else {
		printf("ɾ��ʧ��");
	}

	//4)���ҵڶ����� ��֤��GetElem_L����
	printf("Ѱ�ҵڶ�����\n");
	e = 0;
	if (GetElem_L(head, 3, &e)) {
		printf("�ҵ���Ϊ:%d\n", e);
		printf("\n");
	}
	else
	{
		printf("δ�ҵ���Ӧ����\n");
	}

	//5)�鲢�������������µ����� ��֤��MergeList_L����
	printf("����head2\n");
	LinkList head2 = (LinkList)malloc(sizeof(LNode));
	CreateList_L(head2, 3);
	printAll(head2);
	printf("\n");
	LinkList head3 = (LinkList)malloc(sizeof(LNode));
	MergeList_L(head, head2, &head3);
	printAll(head3);

	system("pause");
	return;
}
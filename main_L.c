#include<stdio.h>	
#include"LNode.h"
int main() {

	//-----验证链表-----
	printf("-----验证链表-----\n");
	//1)建立链表
	LinkList head = (LinkList)malloc(sizeof(LNode));
	CreateList_L(head, 5);
	printAll(head);
	printf("\n");

	//2)插入一些元素: 10 23 验证：ListInsert_L函数
	printf("插入一些元素: 10,23 \n");
	ListInsert_L(head, 2, 10);
	ListInsert_L(head, 3, 23);
	printAll(head);
	printf("\n");

	//3)删除第二个数 验证：ListDelte_L函数
	printf("删除第二个数\n");
	int e=0;
	if (ListDelte_L(head, 2, &e))
	{
		printf("删除%d成功！\n",e); 
		printAll(head);
		printf("\n");
	}
	else {
		printf("删除失败");
	}

	//4)查找第二个数 验证：GetElem_L函数
	printf("寻找第二个数\n");
	e = 0;
	if (GetElem_L(head, 3, &e)) {
		printf("找到数为:%d\n", e);
		printf("\n");
	}
	else
	{
		printf("未找到相应数！\n");
	}

	//5)归并两个链表，生成新的链表 验证：MergeList_L函数
	printf("链表head2\n");
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
#include<stdio.h>
#include"LnitList.h"

int main() {
	//----��֤˳���-----
	printf("------------��֤˳���------------\n");

	//1)��ʼ��˳���  
	SqList L1;
	InitList_Sq(&L1);

	//2)����һЩԪ��: 10,23,25,15 ��֤��ListInsert_Sq����
	printf("����һЩԪ��: 10,23,25,15 \n");
	ListInsert_Sq(&L1, 1, 10);
	ListInsert_Sq(&L1, 1, 23);
	ListInsert_Sq(&L1, 1, 25);
	ListInsert_Sq(&L1, 1, 15);

	//3)��ӡ��֤
	printAll(&L1);
	printf("\n");

	//4)ɾ��˳���ڶ���25 ��֤��ListDelete_Sq����
	printf("ɾ��˳���ڶ���25\n");
	int e;
	ListDelete_Sq(&L1, 2, &e);
	printf("ɾ�����˳���\n");
	printAll(&L1);
	printf("��ɾ��������%d\n\n", e);

	//5)����˳�����23��λ�� ��֤:LocateElem_Sq����
	int temp = LocateElem_Sq(&L1, 23, compare);
	if (temp) {
		printf("23��λ����˳����еĵ�%d��\n\n", temp);
	}
	else
	{
		printf("˳������ڲ�ѯֵ��\n\n");
	}

	//6���鲢L1��L2(30,40,50)�������±�L3
	SqList L2, L3;
	InitList_Sq(&L2);
	InitList_Sq(&L3);

	ListInsert_Sq(&L2, 1, 30);
	ListInsert_Sq(&L2, 1, 40);
	ListInsert_Sq(&L2, 1, 50);
	printf("˳���L2��\n");
	printAll(&L2);
	printf("�鲢L1��L2��ı�L3��\n");
	MergeList_Sq(L1, L2, &L3);
	printAll(&L3);
	printf("\n");


	system("pause");
	return 0;
}
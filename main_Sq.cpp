#include<stdio.h>
#include"LnitList.h"

int main() {
	//----验证顺序表-----
	printf("------------验证顺序表------------\n");

	//1)初始化顺序表  
	SqList L1;
	InitList_Sq(&L1);

	//2)插入一些元素: 10,23,25,15 验证：ListInsert_Sq函数
	printf("插入一些元素: 10,23,25,15 \n");
	ListInsert_Sq(&L1, 1, 10);
	ListInsert_Sq(&L1, 1, 23);
	ListInsert_Sq(&L1, 1, 25);
	ListInsert_Sq(&L1, 1, 15);

	//3)打印验证
	printAll(&L1);
	printf("\n");

	//4)删除顺序表第二个25 验证：ListDelete_Sq函数
	printf("删除顺序表第二个25\n");
	int e;
	ListDelete_Sq(&L1, 2, &e);
	printf("删掉后的顺序表：\n");
	printAll(&L1);
	printf("被删掉的数：%d\n\n", e);

	//5)查找顺序表中23的位置 验证:LocateElem_Sq函数
	int temp = LocateElem_Sq(&L1, 23, compare);
	if (temp) {
		printf("23的位置是顺序表中的第%d个\n\n", temp);
	}
	else
	{
		printf("顺序表不存在查询值！\n\n");
	}

	//6）归并L1和L2(30,40,50)，产生新表L3
	SqList L2, L3;
	InitList_Sq(&L2);
	InitList_Sq(&L3);

	ListInsert_Sq(&L2, 1, 30);
	ListInsert_Sq(&L2, 1, 40);
	ListInsert_Sq(&L2, 1, 50);
	printf("顺序表L2：\n");
	printAll(&L2);
	printf("归并L1和L2后的表L3：\n");
	MergeList_Sq(L1, L2, &L3);
	printAll(&L3);
	printf("\n");


	system("pause");
	return 0;
}
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

typedef struct {
	int *elem;
	int length;
	int listsize;
}SqList;

//构造一个空的顺序表L
Status InitList_Sq(SqList *L) {
	L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	//存储分配失败
	if (!L->elem)
	{
		exit(OVERFLOW);
	}
	//初始化顺序表长度和容量
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return 0;
}

//在顺序表L第i元素前加入一个元素e
Status ListInsert_Sq(SqList *L, int i, int e) {
	//i有效值为（1≤i≤L.length）
	if (i<1 || i>L->length + 1)
	{
		//i值不合法报错
		return ERROR;
	}
	//储存空间已满，增加分配
	if (L->length >= L->listsize)
	{
		int *newbase = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
		//储存分配失败
		if (!newbase)
		{
			exit(OVERFLOW);
		}
		//新基址
		L->elem = newbase;
		//增加储存容量
		L->listsize += LISTINCREMENT;
	}
	//q为插入位置
	int *q = &(L->elem[i - 1]);
	//插入位置及之后的元素右移
	for (int *p = &(L->elem[L->length - 1]);p >= q;--p) {
		*(p + 1) = *p;
	}
	//插入e
	*q = e;
	//表长增加1
	++L->length;
	//printf("插入成功！\n");
	return OK;
}

//在顺序表L中删除第i个元素，并用e返回其值
Status ListDelete_Sq(SqList *L, int i, int *e) {
	//i有效值为（1≤i≤L.length）
	if (i<1 || i>L->length + 1)
	{
		//i值不合法报错
		return ERROR;
	}
	//p为删除元素的位置
	int *p = &(L->elem[i - 1]);
	//被删除的元素赋值给e
	*e = *p;
	//表尾的位置
	int *q = L->elem + L->length + 1;
	//被删除元素之后的元素左移
	for (++p;p <= q;++p)
	{
		*(p - 1) = *p;
	}
	//表长减少1
	--L->length;
	printf("删除成功！\n");
	return OK;
}

//在顺序表L中查找第1个值与e满足compare（）的元素的位序
Status LocateElem_Sq(SqList *L, int e, Status(*compare)(int, int)) {
	//找到返回在L中的位序，否则返回0
	//初始化i
	int i = 1;
	//p的初始值为第1个元素的储存位置
	int *p = L->elem;
	while (i <= L->length && !(*compare)(*p++, e))
	{
		i++;
	}
	if (i <= L->length)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

//已知顺序表La和Lb按值非递减排列
void MergeList_Sq(SqList La, SqList Lb, SqList *Lc) {
	//归并La和Lb得到新的顺序表Lc
	int *pa = La.elem;
	int *pb = Lb.elem;
	Lc->listsize = Lc->length = La.length + Lb.length;
	int *pc = Lc->elem = (int*)malloc(Lc->listsize * sizeof(int));
	if (!Lc->elem)
	{
		//储存分配失败
		exit(OVERFLOW);
	}
	int *pa_last = La.elem + La.length - 1;
	int *pb_last = Lb.elem + Lb.length - 1;
	//归并
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	//插入La的剩余元素
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	//插入Lb的剩余元素
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}

}
//打印顺序表
void printAll(SqList *L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->elem[i]);
	}
}
//比较两个数 一样返回1，不一样返回0
Status compare(Status a, Status b) {
	if (a == b)
		return 1;
	else
		return 0;
}

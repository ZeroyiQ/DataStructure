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

//����һ���յ�˳���L
Status InitList_Sq(SqList *L) {
	L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	//�洢����ʧ��
	if (!L->elem)
	{
		exit(OVERFLOW);
	}
	//��ʼ��˳����Ⱥ�����
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return 0;
}

//��˳���L��iԪ��ǰ����һ��Ԫ��e
Status ListInsert_Sq(SqList *L, int i, int e) {
	//i��ЧֵΪ��1��i��L.length��
	if (i<1 || i>L->length + 1)
	{
		//iֵ���Ϸ�����
		return ERROR;
	}
	//����ռ����������ӷ���
	if (L->length >= L->listsize)
	{
		int *newbase = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
		//�������ʧ��
		if (!newbase)
		{
			exit(OVERFLOW);
		}
		//�»�ַ
		L->elem = newbase;
		//���Ӵ�������
		L->listsize += LISTINCREMENT;
	}
	//qΪ����λ��
	int *q = &(L->elem[i - 1]);
	//����λ�ü�֮���Ԫ������
	for (int *p = &(L->elem[L->length - 1]);p >= q;--p) {
		*(p + 1) = *p;
	}
	//����e
	*q = e;
	//������1
	++L->length;
	//printf("����ɹ���\n");
	return OK;
}

//��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete_Sq(SqList *L, int i, int *e) {
	//i��ЧֵΪ��1��i��L.length��
	if (i<1 || i>L->length + 1)
	{
		//iֵ���Ϸ�����
		return ERROR;
	}
	//pΪɾ��Ԫ�ص�λ��
	int *p = &(L->elem[i - 1]);
	//��ɾ����Ԫ�ظ�ֵ��e
	*e = *p;
	//��β��λ��
	int *q = L->elem + L->length + 1;
	//��ɾ��Ԫ��֮���Ԫ������
	for (++p;p <= q;++p)
	{
		*(p - 1) = *p;
	}
	//������1
	--L->length;
	printf("ɾ���ɹ���\n");
	return OK;
}

//��˳���L�в��ҵ�1��ֵ��e����compare������Ԫ�ص�λ��
Status LocateElem_Sq(SqList *L, int e, Status(*compare)(int, int)) {
	//�ҵ�������L�е�λ�򣬷��򷵻�0
	//��ʼ��i
	int i = 1;
	//p�ĳ�ʼֵΪ��1��Ԫ�صĴ���λ��
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

//��֪˳���La��Lb��ֵ�ǵݼ�����
void MergeList_Sq(SqList La, SqList Lb, SqList *Lc) {
	//�鲢La��Lb�õ��µ�˳���Lc
	int *pa = La.elem;
	int *pb = Lb.elem;
	Lc->listsize = Lc->length = La.length + Lb.length;
	int *pc = Lc->elem = (int*)malloc(Lc->listsize * sizeof(int));
	if (!Lc->elem)
	{
		//�������ʧ��
		exit(OVERFLOW);
	}
	int *pa_last = La.elem + La.length - 1;
	int *pb_last = Lb.elem + Lb.length - 1;
	//�鲢
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
	//����La��ʣ��Ԫ��
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	//����Lb��ʣ��Ԫ��
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}

}
//��ӡ˳���
void printAll(SqList *L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->elem[i]);
	}
}
//�Ƚ������� һ������1����һ������0
Status compare(Status a, Status b) {
	if (a == b)
		return 1;
	else
		return 0;
}

#include<stdio.h>
#include"JosephRIng.h"


int main()
{
	int n, m;
	LNode *L = (LNode *)malloc(sizeof(LNode));
	printf("����μӵ�����:");
	scanf("%d", &n);
	while (n<=0)
	{
		printf("���벻��ȷ������������\n");
		scanf("%d", &n);
	}
	L = Create_Joseph(L, n);
	printf("������ʼ��������ֵ:");
	scanf("%d", &m);
	while (m<=0)
	{
		printf("���벻��ȷ������������\n");
		scanf("%d", &m);
	}
	Output_Joseph(L, m, n);
	system("pause");
	return 0;
}

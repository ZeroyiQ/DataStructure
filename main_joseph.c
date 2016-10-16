#include<stdio.h>
#include"JosephRIng.h"


int main()
{
	int n, m;
	LNode *L = (LNode *)malloc(sizeof(LNode));
	printf("输入参加的人数:");
	scanf("%d", &n);
	while (n<=0)
	{
		printf("输入不正确，请重新输入\n");
		scanf("%d", &n);
	}
	L = Create_Joseph(L, n);
	printf("输入起始报数上限值:");
	scanf("%d", &m);
	while (m<=0)
	{
		printf("输入不正确，请重新输入\n");
		scanf("%d", &m);
	}
	Output_Joseph(L, m, n);
	system("pause");
	return 0;
}

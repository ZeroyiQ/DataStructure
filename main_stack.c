#include<stdio.h>
#include<string.h>
#include"Stack.h"

int main() {
	OperatorStack operatorStack;
	char result = ' ';
	
	//����һ���ַ���
	char *str = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	int length;
	
	/*��ʼ��operatorStack*/
	initStack(&operatorStack);
	printf("������һ���ַ���\n");
	scanf("%s", str);
	length = strlen(str);
	for ( int i = 0; i < length; i++)
	{
		push(&operatorStack, str[i]);
	}
	
	/*��֤gettop����*/
	result = getTop(&operatorStack);
	printf("����Ԫ�أ�%c\n", result);

	/*��֤pop����ӡstack����*/
	printf("���ζ�ȡstack���ݣ�\n");
	while (getTop(&operatorStack))
	{
		pop(&operatorStack, &result);
		printf("%C\n", result);
	}
	system("pause");
	return 0;
}
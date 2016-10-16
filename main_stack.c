#include<stdio.h>
#include<string.h>
#include"Stack.h"

int main() {
	OperatorStack operatorStack;
	char result = ' ';
	
	//分配一个字符串
	char *str = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	int length;
	
	/*初始化operatorStack*/
	initStack(&operatorStack);
	printf("请输入一串字符：\n");
	scanf("%s", str);
	length = strlen(str);
	for ( int i = 0; i < length; i++)
	{
		push(&operatorStack, str[i]);
	}
	
	/*验证gettop方法*/
	result = getTop(&operatorStack);
	printf("顶部元素：%c\n", result);

	/*验证pop，打印stack内容*/
	printf("依次读取stack内容：\n");
	while (getTop(&operatorStack))
	{
		pop(&operatorStack, &result);
		printf("%C\n", result);
	}
	system("pause");
	return 0;
}
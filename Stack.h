#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR  0
#define TRUE 1
#define FALSE 0
#define OK 1
#define INFEASIBLE -1
#define OVERFLOW -2


/*����ṹ��*/
typedef struct {
	char *base;		//��ַ
	char *top;		//��ָ��
	int size;		//����
}OperatorStack;

int initStack(OperatorStack *stack);	//stack��ʼ��
char getTop(OperatorStack *stack);		//��ȡstack��Ԫ��
int push(OperatorStack *stack, char i);	//ѹջ
int pop(OperatorStack *stack, char *i);	//��ջ

int initStack(OperatorStack * stack)
{
	stack->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (stack->base == NULL) {
		printf("Stack�ռ����ʧ��\n");
		exit(OVERFLOW);
	}
	stack->top = stack->base;
	stack->size = STACK_INIT_SIZE;
	printf("Stack��ʼ�����");

	return 0;
}

char getTop(OperatorStack * stack)
{
	if (stack->base == stack->top)
	{
		return ERROR;
	}

	return *(stack->top - 1);
}

int push(OperatorStack * stack, char i)
{
	if (stack->top - stack->base >= stack->size)
	{
		printf("�����¿ռ�ɹ�");
		stack->size = stack->size + STACKINCREMENT;
		stack->base = (char *)realloc(stack->base, (stack->size) * sizeof(int));
	}
	if (stack->base == NULL)
	{
		printf("�����¿ռ�ʧ��");
		exit(OVERFLOW);
	}
	*stack->top = i;
	stack->top++;
	return 0;
}

int pop(OperatorStack * stack, char * i)
{
	if (stack->top == stack->base) {
		printf("stack����Ԫ��");
		return ERROR;
	}
	*i = *(stack->top - 1);
	stack->top--;

	return 0;
}

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


/*定义结构体*/
typedef struct {
	char *base;		//基址
	char *top;		//顶指针
	int size;		//容量
}OperatorStack;

int initStack(OperatorStack *stack);	//stack初始化
char getTop(OperatorStack *stack);		//获取stack顶元素
int push(OperatorStack *stack, char i);	//压栈
int pop(OperatorStack *stack, char *i);	//弹栈

int initStack(OperatorStack * stack)
{
	stack->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (stack->base == NULL) {
		printf("Stack空间分配失败\n");
		exit(OVERFLOW);
	}
	stack->top = stack->base;
	stack->size = STACK_INIT_SIZE;
	printf("Stack初始化完毕");

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
		printf("增加新空间成功");
		stack->size = stack->size + STACKINCREMENT;
		stack->base = (char *)realloc(stack->base, (stack->size) * sizeof(int));
	}
	if (stack->base == NULL)
	{
		printf("增加新空间失败");
		exit(OVERFLOW);
	}
	*stack->top = i;
	stack->top++;
	return 0;
}

int pop(OperatorStack * stack, char * i)
{
	if (stack->top == stack->base) {
		printf("stack中无元素");
		return ERROR;
	}
	*i = *(stack->top - 1);
	stack->top--;

	return 0;
}

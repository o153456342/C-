#include "stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;//初始给0，top指向栈顶元素的下一个；
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}

	ps->a[ps->top] = x;
	ps->top++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);//栈空了，直接终止报错

	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);//栈空了，直接终止报错

	return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}
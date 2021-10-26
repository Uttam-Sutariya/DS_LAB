//Implement a program to conver in-fix notation to post-fix notation using stack

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//stack structure
struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

//create stack of given input string size
struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*)
		malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int*) malloc(stack->capacity *
								sizeof(int));

	return stack;
}

//check if the stack is empty or not
int isEmpty(struct Stack* stack){
	return stack->top == -1 ;
}

//peek the top element of the stack
char peek(struct Stack* stack){
	return stack->array[stack->top];
}

//remove & return the top element of the stack
char pop(struct Stack* stack){
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}

//push the character on the top of the stack
void push(struct Stack* stack, char op){
	stack->array[++stack->top] = op;
}

//check if encountered character is operand or not
int isOperand(char ch){
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z');
}

//check precedance of operator
int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

//this function convert infix expression to postfix
int infixToPostfix(char exp[])
{
	int i, k;
	char polish[strlen(exp)];

	struct Stack* stack = createStack(strlen(exp));
	if(!stack) // stack created successfully
		return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		//if operand then add to output
		if (isOperand(exp[i]))
			polish[++k] = exp[i];
		
		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (exp[i] == '(')
			push(stack, exp[i]);
		
		// If the scanned character is an ‘)’,
		// pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				polish[++k] = pop(stack);
			pop(stack);
		}
		else // an operator is encountered
		{
			while (!isEmpty(stack) &&
				Prec(exp[i]) <= Prec(peek(stack)))
				polish[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}

	// pop all the operators from the stack
	while (!isEmpty(stack))
		polish[++k] = pop(stack );

	polish[++k] = '\0';
	printf( "%s", polish );
}

//Driven code
int main()
{
	// char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	char exp[] = "a*b+c*d";
	infixToPostfix(exp);
	return 0;
}

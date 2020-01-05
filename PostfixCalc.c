//Postfix Calculator
//Author: Jatin Arora
//--------------------------------------------------------------------BEGINNING---------------------------------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 20
// stack which contains the elements of the expression. 
struct datastack{

	int top;
	unsigned int length;
	int* a;

};

// Few operations on the datastack.

// create function creates a stack for the expression to be evaluated.
struct datastack* create(unsigned int length){
	
	struct datastack* stack = (struct datastack*) malloc(sizeof(struct datastack));

	// Checking if the memeory is available.
	if(stack == NULL){
		printf("Memory not available\n");
		exit(1);
	}

	// allocating the values for the top, length, and allocating size for the array 'a'. 
	stack->top = -1;
	stack->length = length;
	stack->a = (int*) malloc(stack->length * sizeof(int));

	// Checking if the memory is available.
	if(stack->a == NULL){
		printf("Memory not available\n");
		exit(1);
	}

	// returning the pointer variable which is of type 'datastack'.
	return stack;
}

// isEmpty fuction checks whether the datastack is empty.
int isEmpty(struct datastack* stack){

	return stack->top == -1;

}

// pop function removes an element from the datastack.
char pop(struct datastack* stack){

	if(!isEmpty(stack))
		return stack->a[stack->top--];
	return '~';
}

// push function enters an element in the datastack.
void push(struct datastack* stack, char operand){

	stack->a[++stack->top] = operand;
}

// peek function returns the topmost value in the datastack.
char peek(struct datastack* stack){

	return (stack->a[stack->top]);
}

//pfEvaluate function evaluates the expressions.
int pfEvaluate(struct datastack* stack, char* expression){

	int j, countdigits = 0, countoperators = 0;

	for(j=0; expression[j] ; ++j){

		// To check if the jth element of the expression is an operand or an operator.
		// if operand the push into the datastack.
		if(isdigit(expression[j])){
			countdigits++;
			push(stack, expression[j]-'0');
		}
		// if operator the pop two operands from the datastack.
		else{
			countoperators++;
			int op1 = pop(stack);
			int op2 = pop(stack);
			switch (expression[j]){

				case '*': push(stack, op2*op1);
					  break;
				case '+': push(stack, op2+op1);
					  break;
				case '-': push(stack, op2-op1);
					  break;
				case '/': push(stack, op2/op1);
					  break;
				case '%': push(stack, op2%op1);
					  break;
				case '^': push(stack, pow(op2,op1));
					  break;
				default: printf("Operator not defined.");
			} 
		}
	}
	//checking if the expression is valid.
	if(countoperators >= countdigits){
		printf("Wrong Expression\n");
		exit(1);
	}
	//returning the answer.
	return pop(stack);
}

//loop function helps to take the user expressions again.
char loop(struct datastack* stack){
	char choice;
	printf("\nDo you want to Continue.\nPress y/Y to continue.\nPress n/N to exit.\n");
	scanf("%c", &choice);
	scanf("%c", &choice);
	if (choice == 'y' || choice == 'Y')
		return 'y';
	else{
		free(stack);
		return 'n';
	}
}

//The main function starts here.
int main(){
	char again = 'y';
	unsigned int len;
	char expression[MAX];
	while(again == 'y'){
		printf("Enter the postfix expression:\n");
		scanf("%s", expression);
 		len = strlen(expression);
		struct datastack* stack = create(len);
		if(stack == NULL){
		printf("Memory not available");
		exit(1);
		}
		printf("Postfix Evaluation of the Expression: %d", pfEvaluate(stack, expression));
		again = loop(stack);
	}
	return 0;
}

//-----------------------------------------------------------------------END-----------------------------------------------------------------------------------------//

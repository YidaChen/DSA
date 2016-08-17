#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Stack {
    
    int top;
    unsigned capacity;
    int *array;
} Stack;

Stack* new_Stack(unsigned capacity){
    
    Stack *stack = malloc(sizeof(Stack));
    stack->array = malloc(sizeof(int)*capacity);
    stack->capacity = capacity;
    stack->top = -1;
    
    return stack;
}

bool isFull(Stack *stack){
    return stack->top == stack->capacity-1;
}

bool isEmpty(Stack *stack){
    return stack->top == -1;
}

void push(Stack *stack, int item){
    
    if(!isFull(stack))
        stack->array[++stack->top] = item;
}

int pop(Stack *stack){
    
    if(!isEmpty(stack)){
        return stack->array[stack->top--];
    }
}

int peek(Stack *stack){
    
    if(!isEmpty(stack)){
        return stack->array[stack->top];
    }
}

int main(){
    
    Stack *stack = new_Stack(6);
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    
    while(!isEmpty(stack)){
        printf("%d ", pop(stack));
    }
}
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    
    Node *head;
} Stack;

Stack* new_Stack(){
    
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

Node* new_Node(int data){
    
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Stack *stack, int data){
    
    Node *node = new_Node(data);
    node->next = stack->head;
    stack->head = node;
}

bool isEmpty(Stack *stack){
    
    return stack->head == NULL;
}

int pop(Stack *stack){
    
    if(!isEmpty(stack)){
        
        Node *node = stack->head;
        stack->head = stack->head->next;
        
        int data = node->data;
        free(node);
        return data;
    }
}

int peek(Stack *stack){
    
    if(!isEmpty(stack))
        return stack->head->data;
}

int main(){
    
    Stack *stack = new_Stack();
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    
    while(!isEmpty(stack)){
        printf("%d ", pop(stack));
    }
    
}
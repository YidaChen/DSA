#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    
    Node *front, *rear;
} Queue;

Queue* new_Queue(){
    Queue *queue = malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

Node* new_Node(int data){
    
    Node *node = malloc(sizeof(node));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(Queue *queue, int data){
    
    Node *node = new_Node(data);
    if(queue->rear == NULL){
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

int dequeue(Queue *queue){
    
    if(queue->front == NULL) 
        return NULL;
    Node *node = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL) 
        queue->rear = NULL;
    
    int data = node->data;
    free(node);
    return data;
}

int main(){
    
    Queue *queue = new_Queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    dequeue(queue);
    enqueue(queue, 3);
    enqueue(queue, 4);
    
    while(queue->front){
        printf("%d ", dequeue(queue));
    }
}
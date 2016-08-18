#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Queue {
    
    int front, rear, size, capacity;
    int *array;
} Queue;

Queue* new_Queue(int capacity){
    
    Queue *queue = malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->array = malloc(sizeof(int)*capacity);
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}

bool isFull(Queue *queue){
    return queue->size == queue->capacity;
}

bool isEmpty(Queue *queue){
    return queue->size == 0;
}

void enqueue(Queue *queue, int item){
    
    if(isFull(queue)) return;
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue *queue){
    
    if(isEmpty(queue)) return NULL;
    queue->front = (queue->front+1) % queue->capacity;
    int item = queue->array[queue->front];
    
    queue->size--;
    return item;
}

int front(Queue *queue){
    
    if(isEmpty(queue)) return NULL;
    return queue->array[queue->front];
}

int rear(Queue *queue){
    
    if(isEmpty(queue)) return NULL;
    return queue->array[queue->rear];
}

int main(){
    
    Queue *queue = new_Queue(3);
    enqueue(queue, 1);
    enqueue(queue, 2);
    dequeue(queue);
    enqueue(queue, 3);
    enqueue(queue, 4);
    
    while(!isEmpty(queue)){
        printf("%d ", dequeue(queue));
    }
}
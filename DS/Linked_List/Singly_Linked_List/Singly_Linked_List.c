#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    
    int data;
    struct Node *next;
} Node;
Node* new_Node(int data){
    
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
//根據index得到node
Node* getNode(Node **headRef ,int index){
    int pos = 0;
    Node* current = *headRef;
    while(pos++ < index){
        current = current->next;
    }
    return current;
}
//找出data的index
int indexOf(Node **headRef ,int data){
    
    Node *current = *headRef;
    int index = 0;
    
    while(current){
        if(current->data == data){
            return index;
        }
        index++;
        current = current->next;
    }
    return -1;
}
//將data插入到index的位置
void insert(Node **headRef, int index, int data){
    
    Node *prev = getNode(headRef ,index-1);
    Node *newNode = new_Node(data);
    
    newNode->next = prev->next;
    prev->next = newNode;
}
//將data插入開頭
void insertFirst(Node **headRef, int data){
    
    Node *newNode = new_Node(data);
    newNode->next = *headRef;
    *headRef = newNode;
}
//將data插入結尾
void insertLast(Node **headRef, int data){
    
    Node *newNode = new_Node(data);
    newNode->next = NULL;
    if(!*headRef){
        *headRef = newNode;
        return;
    }
    Node *last = *headRef;
    
    while(last->next){
        last = last->next;
    }
    last->next = newNode;
}
//移除在index位置的node, 並返回data
int removeAt(Node **headRef ,int index){
    
    Node *current;
    if(index == 0){
        current = *headRef;
        *headRef = current->next;
    } else {
        Node *prev = getNode(headRef, index-1);
        current = prev->next;
        prev->next = current->next;   
    }
    
    return current->data;
}
//移除list裡的data, 並返回
int removeNode(Node **headRef ,int data){
    int index = indexOf(headRef, data);
    return removeAt(headRef, index);
}

void printList(Node *node){
    while(node){
        printf("%d ", node->data);
        node = node->next;
    }
}
int main() {
    Node *head = NULL;
    insertLast(&head, 0);
    insertFirst(&head, 1);
    insertFirst(&head, 2);
    insertFirst(&head, 3);
    insertLast(&head, 4);
    insert(&head, 1, 5);
    
    removeAt(&head, 0);
    removeNode(&head, 4);
    printList(head);
    
    //printf("\n %d", indexOf(&head, 4));
    return 0;
}
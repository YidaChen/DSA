#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct DoublyLinkedList {
    
    int length;
    Node *head;
    Node *tail;
} DLL;

DLL* new_DoublyLinkedList() {
    
    DLL *dll = malloc(sizeof(DLL));
    dll->length = 0;
    dll->head = NULL;
    dll->tail = NULL;
    return dll;
}

Node* new_Node(int data){
    
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

Node* getNode(DLL *dll, int index){
    
    if(index < 0 || index >= dll->length){
        return NULL;
    }
    int i = 0;
    Node *current;
    if(index <= dll->length/2){
        
        current = dll->head;
        while(i++ < index){
            current = current->next;
        }
    } else {
        
        current = dll->tail;
        int rIndex = dll->length - (index+1);
        while(i++ < rIndex){
            current = current->prev;
        }
    }
    return current;
}

int get(DLL *dll, int index){
    
    if(index < 0 || index >= dll->length){
        return NULL;
    }
    return getNode(dll, index)->data;
}

bool insertFirst(DLL *dll, int data){
    
    Node *node = new_Node(data);
    
    if(dll->head){
        node->next = dll->head;
        dll->head->prev = node;
    }
    else {
        dll->tail = node;
    }
    dll->head = node;
    dll->length++;
    return true;
}

bool insertLast(DLL *dll, int data){
    
    Node *node = new_Node(data);
    
    if(dll->head){
        node->prev = dll->tail;
        dll->tail->next = node;
    }
    else {
        dll->head = node;
    }
    dll->tail = node;
    dll->length++;
    return true;
}

bool insert(DLL *dll, int index, int data){
    if(index < 0 || index > dll->length){
        return false;
    }
    if(index == 0){
        return insertFirst(dll, data);
    }
    if(index == dll->length){
        return insertLast(dll, data);
    }
    Node *node = new_Node(data);
    Node *next = getNode(dll, index);
    
    node->next = next;
    node->prev = next->prev;
    next->prev->next = node;
    next->prev = node;
    
    dll->length++;
    return true;
}

Node* removeAt(DLL *dll, int index){
    
    if(index < 0 || index >= dll->length){
        return NULL;
    }
    
    Node *node = getNode(dll, index);
    
    if(index == 0){
        dll->head = node->next;
    } else {
        node->prev->next = node->next;
    }
    if(index == dll->length - 1){
        dll->tail = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    dll->length--;
    return node;
}

int indexOf(DLL *dll, int data){
    
    Node *current = dll->head;
    int index = -1;
    
    while(++index < dll->length){
        if(current->data == data){
            return index; 
        }
        current = current->next;
    }
    return -1;
}

void removeNode(DLL *dll, int data){
    
    int index = indexOf(dll, data);
    removeAt(dll, index);
}

void printList(DLL *dll){
    
    Node *current = dll->head;
    while(current){
        
        printf("%d ", current->data);
        current = current->next;
    }
}

int main(){
    
    DLL *dll = new_DoublyLinkedList();
    insertLast(dll, -1);
    insertFirst(dll, 0);
    insertFirst(dll, 1);
    insertFirst(dll, 2);
    insertLast(dll, -2);
    insert(dll, 0, 3);
    insert(dll, 6, -3);
    removeNode(dll, 0);
    
    printList(dll);
    
    printf("\n %d",get(dll, -1));
}
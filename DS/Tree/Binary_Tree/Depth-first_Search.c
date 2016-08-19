#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    
    int data;
    struct Node *left, *right;
} Node;

Node* new_Node(int data){
    
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preOrder(Node *node){
    
    if(node == NULL) return;
    
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node){
    
    if(node == NULL) return;
    
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

void postOrder(Node *node){
    
    if(node == NULL) return;
    
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main(){
    
    Node *root = new_Node(1);
    root->left = new_Node(2);
    root->right = new_Node(3);
    root->left->left = new_Node(4);
    root->left->right = new_Node(5); 
    
    preOrder(root);     printf("\n");
    inOrder(root);      printf("\n");
    postOrder(root);
}
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    
    int key;
    struct Node *left, *right;
} Node;

Node* new_Node(int key){
    
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
//return root
Node* insert(Node *node, int key){
    
    if(node == NULL) return new_Node(key);
    
    if(key < node->key){
        node->left = insert(node->left, key);
    } 
    else if(key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

Node* searchNode(Node *node, int key){
    
    if(node == NULL) return NULL;
    if(node->key == key) return node;
    
    if(key < node->key){
        return searchNode(node->left, key);
    }  
    return searchNode(node->right, key);
}

Node* findMinNode(Node *node){
    
    while(node->left)
        node = node->left;
    return node;
}
//return root
Node* deleteNode(Node *node, int key){
    
    if(node == NULL) return NULL;
    
    if(key < node->key){
        node->left = deleteNode(node->left, key);
    } 
    else if(key > node->key){
        node->right = deleteNode(node->right, key);
    } 
    else{
        if(node->left == NULL){
            Node *right = node->right;
            free(node);
            return right;
        }
        if(node->right == NULL){
            Node *left = node->left;
            free(node);
            return left;
        }
        Node *temp = findMinNode(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

int min(Node *node){
    
   if(node == NULL) return NULL;
    
    while(node->left)
        node = node->left;
    return node->key;
}

int max(Node *node){
    
    if(node == NULL) return NULL;
    
    while(node->right)
        node = node->right;
    return node->key;
}

void inorder(Node *node){
    
    if(node == NULL) return;
    
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

int main(){
    
    Node *root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    inorder(root);      printf("\n");
    root = deleteNode(root, 50);
    inorder(root);      printf("\n");
    printf("%d ", min(root));
    printf("%d", max(root));
}
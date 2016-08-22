#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    
    int key, h;
    struct Node *left, *right;
} Node;

Node* new_Node(int key){
    
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->h = 1;
    return node;
}

int max(int a, int b){ return a > b ? a : b; }

int h(Node *node){
    
    if(node == NULL) return 0;
    return node->h;
}

int getBalance(Node *n){ 
    return h(n->left) - h(n->right); 
}

Node* rightRotate(Node *node){
    
    Node *root = node->left;
    node->left = root->right;
    root->right = node;
    
    node->h = max(h(node->left), h(node->right))+1;
    root->h = max(h(root->left), h(root->right))+1;
    
    return root;
}

Node* leftRotate(Node *node){
    
    Node *root = node->right;
    node->right = root->left;
    root->left = node;
    
    node->h = max(h(node->left), h(node->right))+1;
    root->h = max(h(root->left), h(root->right))+1;
    
    return root;
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
    
    node->h = max(h(node->left), h(node->right))+1;
    int balance = getBalance(node);
    //left left
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }
    //right right
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    //left right
    if(balance > 1 && key > node->left->key){
        
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //right left
    if(balance < -1 && key < node->right->key){
        
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
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
        if(node->left == NULL && node->right == NULL){
            free(node);
            return NULL;
        }
        if(node->left == NULL || node->right == NULL){
            Node *temp = node->right ? node->right : node->left;
            *node = *temp;
            free(temp);
        } else {
            Node *temp = findMinNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }
    node->h = max(h(node->left), h(node->right))+1;
    int balance = getBalance(node);
    //left left
    if(balance > 1 && getBalance(node->left) >= 0){
        return rightRotate(node);
    }
    //left right
    if(balance > 1 && getBalance(node->left) < 0){
        
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //right right
    if(balance < -1 && getBalance(node->right) <= 0){
        return leftRotate(node);
    }
    //right left
    if(balance < -1 && getBalance(node->right) > 0){
        
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

void preorder(Node *node){
    
    if(node == NULL) return;
    
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
}

int main(){
    
    Node *root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
    preorder(root);      printf("\n");
    root = deleteNode(root, 10);
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
    preorder(root);
}
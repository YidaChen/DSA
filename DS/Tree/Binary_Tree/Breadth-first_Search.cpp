#include <stdio.h>
#include <malloc.h>
#include <queue>
using namespace std;

typedef struct Node {
    
    int data;
    struct Node *left, *right;
} Node;

Node* new_Node(int data){
    
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int height(Node *node){
    
    if(node == NULL) return 0;
    
    int lheight = height(node->left);
    int rheight = height(node->right);
    
    if(lheight > rheight) 
        return lheight + 1;
        
    return rheight + 1;
}

void printGivenLevel(Node *node, int level){
    
    if(node == NULL) return;
    
    if(level == 1){
        printf("%d ", node->data);
    } else if(level > 1){
        printGivenLevel(node->left, level-1);
        printGivenLevel(node->right, level-1);
    }
}

void printLevelOrder_recursive(Node *root){
    
    int h = height(root);
    for(int i = 1; i <= h; i++){
        printGivenLevel(root, i);
    }
}

void printLevelOrder_queue(Node *root){
    
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
   
    Node *node;
    while(node = q.front()){
        
        printf("%d ", node->data);
        q.pop();
        
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
}

int main()
{
    Node *root = new_Node(1);
    root->left = new_Node(2);
    root->right = new_Node(3);
    root->left->left = new_Node(4);
    root->left->right = new_Node(5);
 
    printLevelOrder_recursive(root);
    printf("\nLevel Order traversal of binary tree \n");
    printLevelOrder_queue(root);
}
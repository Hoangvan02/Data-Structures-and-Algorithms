#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
//Tao nut moi 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// Duyet bst 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
//Chen them nut vao BST
struct node* insert(struct node* node, int key) 
{ 
    //neu cay rong tra ve gia tri la nut moi
    if (node == NULL) return newNode(key); 
  
    //neu khong viet lai cay
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    //tra ve con tro
    return node; 
} 
   
int main() 
{ 
    
    struct node *root = NULL; 
    root = insert(root, 100); 
    roinsert(root, 20); 
    insert(root, 10); 
    insert(root, 500); 
    insert(root, 10); 
    insert(root, 30); 
    insert(root, 40); 
    insert(root, 35);
   
    printf("Cây nhị phân là:");
    inorder(root); 
   
    return 0; 
} 

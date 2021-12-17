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
   
// Duyet bst thu tu giua
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
//duyet bst thu tu trc
void perorder(struct node *root){
	if(root !=NULL){
		printf("%d\n",root->key);
		perorder(root->left);
		perorder(root->right);
	}
}
//Duyet bst thu tu sau
void posorder(struct node *root){
        if(root !=NULL){
                posorder(root->left);
                posorder(root->right);
		printf("%d\n",root->key);
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
    insert(root, 20); 
    insert(root, 10); 
    insert(root, 500); 
    insert(root, 10); 
    insert(root, 30); 
    insert(root, 40); 
   
    // in chuong trinh duyet 
    printf("Duyet cay theo thu tu giua\n");
    inorder(root); 
    printf("Duyet cay theo thu tu truoc\n");
    perorder(root);
    printf("Duyet cay theo thu tuw sau\n");
    posorder(root);
    return 0; 
} 

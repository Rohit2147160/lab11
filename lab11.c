//Rohit Priyadarshi
//2147160
//3MCA A

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct node {
	int key;
	struct node *left,*right;
};


struct node* newNode(int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}


struct node* insert(struct node* node, int key)
{
	
	if (node == NULL)
		return newNode(key);
		
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int ceil(struct node * root,int data){
	if(root == NULL){
		return -1;
	}
	if(root->key == data){
		return root->key;
	}
	if(root->key < data){
		return ceil(root->right,data);
	}
	int c = ceil(root->left,data);
	return (c >= data) ? c: root->key;
}

int floor(struct node* root, int key)
{
    if (!root)
        return INT_MAX;
 
   
    if (root->key == key)
        return root->key;

    if (root->key > key)
        return floor(root->left, key);
 

    int floorValue = floor(root->right, key);
    return (floorValue <= key) ? floorValue : root->key;
}
 




int main(){
	struct node *root = NULL;
	int n ;
	printf("\n Enter the root element: \n");
	scanf("%d",&n);
	root = insert(root, n);
	int ch,val,no;
	while(1)
	{
		printf("\n1. Construct the tree \n2. Display \n3. Floor and Ceil:\n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the no to be inserted: \n");
				scanf("%d",&val);
				insert(root,val);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				printf("\nEnter the no : \n");
				scanf("%d",&no);
				int c = ceil(root,no);
				int f = floor(root,no);
				printf("Ceil value : %d\n",c);
				printf("Floor value : %d",f);
				break;
			default:
				printf("Wrong Input");
				
		}
	}
	return 0;
}

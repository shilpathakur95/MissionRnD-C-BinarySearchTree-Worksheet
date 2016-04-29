/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorder_wrapper(struct node *root, int *arr, int *value)
{
	if (root != NULL)
	{

		inorder_wrapper(root->left, arr, value);
		*(arr + *value) = root->data;
		*value = *value + 1;
		inorder_wrapper(root->right, arr, value);
	}
}

void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int value = 0;
	inorder_wrapper(root, arr, &value);
}
void preorder_wrapper(struct node *root, int *arr, int *value)
{
	if (root != NULL)
	{
		*(arr + *value) = root->data;
		*value = *value + 1;
		preorder_wrapper(root->left, arr, value);
		preorder_wrapper(root->right, arr, value);
	}
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int value = 0;
	preorder_wrapper(root, arr, &value);
}
void postorder_wrapper(struct node *root, int *arr, int *value){
	if (root != NULL)
	{
		postorder_wrapper(root->left, arr, value);
		postorder_wrapper(root->right, arr, value);
		*(arr + *value) = root->data;
		*value = *value + 1;
	}
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int value = 0;
	postorder_wrapper(root, arr, &value);
}
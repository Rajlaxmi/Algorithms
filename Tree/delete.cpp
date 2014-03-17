#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

//Delete is similar to post-order traversal
void deleteTree(node** rootptr)
{
	node*& root = *rootptr;
	if(root != NULL)
	{
		deleteTree(&root->left);
		deleteTree(&root->right);
		free(root);
		root = NULL; //Do this manually since it is not set to NULL and can cause problems
	}
}

void insert(node** ptrhead, int data)
{
	node* &head = *ptrhead;
	if(head == NULL)
	{
		head = new node;
		head->data = data;
		head->left = NULL;
		head->right = NULL;
	}
	else
	{
		if(head->data < data)
			insert(&head->right, data);
		else
			insert(&head->left, data);
	}
}

int main()
{
	node* head = NULL; //Always initialize to NULL if want to compare with NULL afterwards
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 6);
	deleteTree(&head);
}


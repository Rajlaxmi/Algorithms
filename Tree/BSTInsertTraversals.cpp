#include <iostream>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

void inOrder(node* root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void preOrder(node* root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		inOrder(root->right);
		cout<<root->data<<" ";
	}
}

void postOrder(node* root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		inOrder(root->left);
		inOrder(root->right);
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
	inOrder(head);
	cout<<endl;
	preOrder(head);
	cout<<endl;
	postOrder(head);
	cout<<endl;
}

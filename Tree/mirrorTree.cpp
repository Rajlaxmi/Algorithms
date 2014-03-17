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

void createMirror(node** ptrhead, node** ptrhead2)
{
	node* &head = *ptrhead;
	node* &head2 = *ptrhead2;
	if(head == NULL)
		head2 = NULL;
	else
	{
		head2 = new node;
		head2->data = head->data;
		createMirror(&head->left, &head2->left);
		createMirror(&head->right, &head2->right);
	}
}

int main()
{
	node* head = NULL; //Always initialize to NULL if want to compare with NULL afterwards
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 6);
	
	node* head2 = NULL;
	createMirror(&head, &head2);
	inOrder(head2);
	cout<<endl;
}


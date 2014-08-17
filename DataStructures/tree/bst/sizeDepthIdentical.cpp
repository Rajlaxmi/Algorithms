#include <iostream>
#include <cmath>
using namespace std;
/** Oututs size of tree, Depth of tree, whether two trees identical or not ***/
struct node
{
	int data;
	node* left;
	node* right;
};

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

int size(node* head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + size(head->left) + size(head->right);
}

bool identical(node* head, node* head2)
{
	if(head == NULL && head2 == NULL)
		return true;
	else if(head == NULL)
		return false;
	else if(head2 == NULL)
		return false;
	else if(head->data == head2->data)	
	{
		bool left = identical(head->left, head2->left);
		if(!left)
			return false;
		else
			return identical(head->right, head2->right);
	}
	else
		return false;
}

int height(node* head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + max(height(head->left), height(head->right));
}

int main()
{
	node* head = NULL; //Always initialize to NULL if want to compare with NULL afterwards
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 6);
	insert(&head, 7);
	
	node* head2 = NULL;
	insert(&head2, 5);
	insert(&head2, 4);
	insert(&head2, 6);
	insert(&head2, 8);
	
	cout<<size(head)<<endl;
	cout<<height(head)<<endl;
	cout<<identical(head, head2)<<endl;
	
}


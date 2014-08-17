#include <iostream>
#include <queue>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

void preOrder(node* root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(node* root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
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

/*** Level Order Traversal ****/
void levelOrder(queue<node*> nodeQueue)
{
	node* top;
	while(nodeQueue.size() > 0)
	{
		top = nodeQueue.front();
		if(top == NULL)
		{
			cout<<endl;
			if(nodeQueue.size() > 1)
				nodeQueue.push(NULL);
		}
		else
		{
			cout<<top->data<<"  ";
			if(top->left != NULL)
				nodeQueue.push(top->left);
			if(top->right != NULL)
				nodeQueue.push(top->right);
		}
		nodeQueue.pop();
	}
}


int main()
{
	node* head = NULL; //Always initialize to NULL if want to compare with NULL afterwards
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 6);
	queue<node*> nodeQueue;
	nodeQueue.push(head);
	nodeQueue.push(NULL);
	levelOrder(nodeQueue);
}


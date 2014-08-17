#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <utility>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

node* insert(node* &curr, int data)
{
	curr = new node;
	curr->data = data;
	curr->left = NULL;
	curr->right = NULL;
	return curr;
}

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

void levelOrder(node* root)
{
	node* temp;
	queue<node*> nodeq;
	nodeq.push(root);
	nodeq.push(NULL);
	while(!nodeq.empty())
	{
		temp = nodeq.front();
		if(temp!=NULL)
		{
			cout<<temp->data<<" ";
			nodeq.pop();
			if(temp->left != NULL)
				nodeq.push(temp->left);
			if(temp->right != NULL)
				nodeq.push(temp->right);
		}
		else
		{
			if(nodeq.size() == 1)
			{
				cout<<endl;
				nodeq.pop();
			}
			else
			{
				cout<<endl;
				nodeq.pop();
				nodeq.push(NULL);
			}
		}
	}
}

node* construct(int* in, int* level, int s, int e, queue<node*> q)
{
	{
		
	}
}

int main()
{
	int in[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int pre[] = {5, 3, 1, 0, 2, 4, 6, 8, 7};
	int post[] = {0, 2, 1, 4, 3, 7, 8, 6, 5};
	int level[] = {5, 3, 6, 1, 4, 8, 0, 2, 7};
	
	pair<node* ,int> root = construct(in, level, 0, 8, 0);
	postOrder(root.first);
	cout<<endl;
	levelOrder(root.first);
	cout<<endl;
	
	return 0;
}






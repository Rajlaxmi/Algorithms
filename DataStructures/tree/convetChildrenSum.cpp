#include <iostream>
#include <queue>
#include <cmath>
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

node* increment(node* root, int data)
{
	if(!root->left && !root->right)
	{
		root->data+=data;
		return root;
	}
	else if(!root->left)
	{
		root->data+=data;
		root->right = increment(root->right, data);
		return root;
	}
	else
	{
		root->data+=data;
		root->left = increment(root->left, data);
		return root;
	}
}


node* convert(node* root)
{
	if(root != NULL)
	{
		root->left = convert(root->left);
		root->right = convert(root->right);
		
		int l = (!root->left)?0:((root->left)->data);
		int r = (!root->right)?0:((root->right)->data);
		if((root->data == (l + r)) || (!(root->left) && !(root->right)))
			return root;
		else
		{
			if(root->data < (l + r))
			{
				root->data = (l + r);
				return root;
			}
			else if(!root->left)
			{
				root->right = increment(root->right, root->data - l - r);
				return root;
			}
			else
			{
				root->left = increment(root->left, root->data - l - r);
				return root;
			}
		}
	}
	else
		return root;
}

int main()
{
	node* root = NULL, *curr = NULL;
	curr = insert(root, 5);
	curr = insert(curr->left, 3);
	curr = insert(curr->left, 1);
	curr = insert(curr->left, 0);
	
	curr = insert((root->left)->right, 4);
	curr = insert(((root->left)->left)->right, 2);
	
	curr = insert(root->right, 6);
	curr = insert(curr->right, 8);
	curr = insert(curr->left, 7);
	
	root = convert(root);
	levelOrder(root);
	
	return 0;
}



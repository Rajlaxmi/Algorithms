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

pair<node* ,int> construct(int* in, int* pre, int s, int e, int pres)//pres needed for starting point in inorder arr
{
	if(s <= e)
	{
		int first = pre[pres];
		//find where in in array
		int i;
		for(i=s; i<=e; i++)
		{
			if(first == in[i])
				break;
		}
		
		//make left and right trees
		pair<node* ,int> l = construct(in, pre, s, i-1, pres + 1);
		pair<node* ,int> r = construct(in, pre, i+1, e, pres + l.second + 1);
		
		//root
		node* root = new node;
		root->data = first;
		root->left = l.first;
		root->right = r.first;
		
		return make_pair(root, l.second + r.second + 1);
	}
	else
	{
		node* temp = NULL;
		return make_pair(temp, 0);
	}
}

int main()
{
	int in[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int pre[] = {5, 3, 1, 0, 2, 4, 6, 8, 7};
	int post[] = {0, 2, 1, 4, 3, 7, 8, 6, 5};
	int level[] = {5, 3, 6, 1, 4, 8, 0, 2, 7};
	
	pair<node* ,int> root = construct(in, pre, 0, 8, 0);
	postOrder(root.first);
	cout<<endl;
	levelOrder(root.first);
	cout<<endl;
	
	return 0;
}





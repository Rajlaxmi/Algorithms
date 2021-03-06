#include <iostream>
#include <queue>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

node* insert(node* &root, int data)
{	
	node* temp = root;
	while(temp != NULL)
	{
		if(temp->data < data)
		{ 
			if(temp->right == NULL)
			{
				temp->right = new node;
				temp = temp->right;
				break;
			}
			else
				temp = temp->right;
		}
		else
		{ 
			if(temp->left == NULL)
			{
				temp->left = new node;
				temp = temp->left;
				break;
			}
			else
				temp = temp->left;
		}
	}
	if(temp == NULL)
	{
		root = new node;
		temp = root;
	}
		
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void levelOrder(node* root)
{
	node *temp;
	queue<node*> ndq;
	ndq.push(root);
	ndq.push(NULL);
	while(!(ndq.size() == 1 && ndq.front()==NULL))
	{
		temp = ndq.front();
		if(temp == NULL)
		{
			cout<<endl;
			ndq.pop();
			ndq.push(NULL);
		}
		else
		{
			cout<<temp->data<<" ";
			ndq.pop();
			if(temp->left != NULL)
				ndq.push(temp->left);
			if(temp->right != NULL)
				ndq.push(temp->right);				
		}
	}
	cout<<endl;
}

void deleteNode(node* &curr)
{
	//find parent
	node* par = NULL;
	while(par->left == curr || par->right == curr) //search
	{
		if(par->data < curr->data)
			par = par->right;
		else
			par = par->left;
	}
	if(curr->left == NULL)
	{
		if(par->left == curr)
		{
			
		}
	}
	else if(curr->right == NULL)
		par->right = NULL;
	else
	{
		//goto left and find its rightmost
		node* temp = par->left;
		while(temp->right != NULL)
			temp = temp->right;
		temp->right = curr->right;
	}
	
}

int main()
{
	node *root=NULL, *curr=NULL;
	insert(root, 5);
	insert(root, 4);
	insert(root, 8);
	insert(root, 7);
	insert(root, 9);
	insert(root, 1);
	insert(root, 0);
	insert(root, 2);
	
	levelOrder(root);
	
	deleteNode(root->right);
	return 0;
}

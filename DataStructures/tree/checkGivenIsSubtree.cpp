#include <iostream>
#include <queue>
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

bool checkIdentical(node* root, node* root2)
{
	if(root2 == NULL)
		return true;
	else if(root == NULL)
		return false;
	else
	{
		if(root->data == root2->data)
			return (checkIdentical(root->left, root2->left) && checkIdentical(root->right, root2->right));
		else
			return false;
	}
		
}


bool isSubtree(node* root, node* root2)
{
	if(root == NULL && root2 == NULL)
		return true;
	else if(root == NULL && root2 != NULL)
		return false;
	else if(root != NULL && root2 == NULL)
		return true;
	else
	{
		if(checkIdentical(root, root2))
			return true;
		else
			return (isSubtree(root->left, root2) || isSubtree(root->right, root2));
	}
}

int main()
{
	node* root = NULL, *curr = NULL, *root2 = NULL, *curr2 = NULL;
	curr = insert(root, 5);
	curr = insert(curr->left, 3);
	curr = insert(curr->left, 1);
	curr = insert(curr->left, 0);
	
	curr = insert((root->left)->right, 4);
	curr = insert(((root->left)->left)->right, 2);
	
	curr = insert(root->right, 6);
	curr = insert(curr->right, 8);
	curr = insert(curr->left, 7);
	
	curr2 = insert(root2, 6);
	curr2 = insert(curr2->right, 8);
	curr2 = insert(curr2->left, 7);
	
	cout<<isSubtree(root, root2)<<endl;
	
	return 0;
}




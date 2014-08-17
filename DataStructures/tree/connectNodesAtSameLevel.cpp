#include <iostream>
#include <queue>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
	node* next;
};

node* insert(node* &curr, int data)
{
	curr = new node;
	curr->data = data;
	curr->left = NULL;
	curr->right = NULL;
	curr->next = NULL;
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

node* connectSameLevel(node* root)
{
	queue<node*> conn, notconn;
	notconn.push(root);
	notconn.push(NULL);
	while(!notconn.empty() && !(notconn.size() == 1 && notconn.front()==NULL))
	{
		node* temp = notconn.front();
		if(temp == NULL)
		{
			conn.push(NULL);
			while(!(conn.front() == NULL))
			{
				temp = conn.front();
				conn.pop();
				temp->next = conn.front();
			}
			conn.pop();
			notconn.push(NULL);
		}
		else
		{
			conn.push(temp);
			notconn.pop();
			if(temp->left != NULL)
				notconn.push(temp->left);
			if(temp->right != NULL)
				notconn.push(temp->right);
		}
	}
}

void print(node* root)
{
	node* temp = root, *temp2=root;
	while(temp!=NULL)
	{
		temp2 = temp;
		while(temp2!=NULL)
		{
			cout<<temp2->data<<" ";
			temp2 = temp2->next;
		}
		temp = temp->left;
	}
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
	
	connectSameLevel(root);
	print(root);
	return 0;
}

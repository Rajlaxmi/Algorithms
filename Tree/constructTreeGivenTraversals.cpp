#include <iostream>
int size = 0;
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
/*** Tree can be build only if one of them is InOrderTraversal ***/

void preOrder(node* root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
		
	}
}

int find(int* arr, int n)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == n)
			return i;
	}
	return -1;
	
}

void createTree(node** headptr, int* inorder, int* preorder, int& i, int start, int end)
{
	if(i >= 0 && i < size)
	{
		int pos = find(inorder, preorder[i]);
		if(pos != -1 && (pos >= start && pos <= end))
		{
			node* &head = *headptr;
			head = new node;
			head->data = preorder[i];
			head->left = NULL;
			head->right = NULL;
			i++;
			createTree(&head->left, inorder, preorder, i , start, pos-1);
			i++;
			createTree(&head->right, inorder, preorder, i , pos+1, end);
		}
		else
			i--;
	}
}

int main()
{
	node* head = NULL; //Always initialize to NULL if want to compare with NULL afterwards
	int inorder[5] = {3, 1, 2, 5, 4};
	int preorder[5] = {1, 3, 2, 5, 4};
	size = 5;
	int i = 0;
	createTree(&head, inorder, preorder, i, 0, size-1);
	preOrder(head);
	cout<<endl;
}


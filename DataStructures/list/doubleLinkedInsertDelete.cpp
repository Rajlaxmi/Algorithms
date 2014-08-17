#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};

node* insert(node* &curr, node* prev, int data)
{
	curr = new node;
	curr->data = data;
	curr->prev = prev;
	curr->next = NULL;
	return curr;
}

node* deleteNode(node* curr, node* head)
{
	if(curr == head)
	{
		node* temp = curr->next;
		free(curr);
		return temp;
	}
	else
	{
		(curr->prev)->next = curr->next;
		free(curr);
		return head;
	}
}

void print(node* head)
{
	while(head !=  NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main()
{
	node* head = NULL, * curr = NULL;
	curr = insert(head, NULL, 1);
	curr = insert(curr->next, curr, 2);
	curr = insert(curr->next, curr, 3);
	curr = insert(curr->next, curr, 4);
	print(head);
	head = deleteNode(head, head);
	head = deleteNode(head->next, head);
	print(head);
	return 0;
}

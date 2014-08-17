
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

node* reverse(node* head)
{
	while(head->next != NULL)
	{
		node* temp = head->next;
		head->next = head->prev;
		head->prev = temp;
		head = head->prev;
	}
	head->next = head->prev;
	head->prev = NULL;
	return head;
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
	head = reverse(head);
	print(head);
	return 0;
}

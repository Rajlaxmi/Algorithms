#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//Delete alternate nodes of a Linked List
struct node
{
	int data;
	node* next;
};

node* insert(node* &curr, int data)
{
	curr = new node;
	curr->data = data;
	curr->next = NULL;
	return curr;
}

void print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
}

node* alternateSplit(node* &head)
{
	if(head == NULL || head->next == NULL)
		return NULL;
	else
	{
		node* temp2 = head->next;
		node* temp = alternateSplit(head->next->next);
		head->next = head->next->next;
		temp2->next = temp;
		return temp2;
	}
}

int main()
{
	node *head = NULL,*head2 = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	curr = insert(curr->next, 7);
	head2 = alternateSplit(head);
	print(head);
	cout<<endl;
	print(head2);
	return 0;
}



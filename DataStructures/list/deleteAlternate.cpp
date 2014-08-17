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

node* delAlternate(node* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	else
	{
		node* temp = head->next;
		head->next = delAlternate(head->next->next);
		free(temp);
		return head;
	}
}

int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	curr = insert(curr->next, 7);
	head = delAlternate(head);
	print(head);
	return 0;
}


#include <iostream>
using namespace std;
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

void middle(node* head)
{
	node *slow=head, *fast=head;
	if(fast!=NULL)
		fast = fast->next;
	while(fast!=NULL && slow!=NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast!=NULL)
			fast = fast->next;
	}
	if(slow!=NULL)
		cout<<slow->data<<endl;
}

int main()
{
	node *head = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr = insert(curr->next, 5);
	//print(head);
	middle(head);
	return 0;
}

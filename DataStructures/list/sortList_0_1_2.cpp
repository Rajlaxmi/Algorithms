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

node* sort(node* head)
{
	node* head0 = NULL, *head1 = NULL, *head2=NULL, *curr0 = NULL, *curr1 = NULL, *curr2 = NULL, *curr = head;
	while(curr != NULL)
	{
		if(curr->data == 0)
		{
			if(head0 == NULL)
				curr0 = insert(head0, curr->data);
			else
				curr0 = insert(curr0->next, curr->data);
			curr = curr->next;
			
		}
		else if(curr->data == 1)
		{
			if(head1 == NULL)
				curr1 = insert(head1, curr->data);
			else
				curr1 = insert(curr1->next, curr->data);
			curr = curr->next;
		}
		else if(curr->data == 2)
		{
			if(head2 == NULL)
				curr2 = insert(head2, curr->data);
			else
				curr2 = insert(curr2->next, curr->data);
			curr = curr->next;
		}
		else
		{
			cout<<"Error!"<<endl;
			return head;
		}
	}
	//conditions
	if(curr0!= NULL)
	{
		curr0->next = head1;
		if(curr1!=NULL)
			curr1->next = head2;
		else
			curr0->next = head2;
		return head0;
	}
	else
	{
		if(curr1!=NULL)
		{
			curr1->next = head2;
			return head1;
		}
		else
			return head2;
	}
	return head;
}

int main()
{
	node *head = NULL,*head2 = NULL, *curr = NULL;
	curr = insert(head, 1);
	curr = insert(curr->next, 0);
	curr = insert(curr->next, 0);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 1);
	curr = insert(curr->next, 1);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 0);
	curr = insert(curr->next, 1);
	curr = insert(curr->next, 1);
	head = sort(head);
	print(head);
	return 0;
}




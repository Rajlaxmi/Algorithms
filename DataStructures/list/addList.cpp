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

node* add(node* head, node* head2, int carry)
{
	if(head != NULL || head2 != NULL)
	{
		if(head2 == NULL)
		{
			head->data = head->data + carry;
			if(head->data > 9)
			{
				head->data%=10;
				head->next = add(head->next, head2, 1);
				return head;
			}
			else
				return head;
		}
		else if(head == NULL)
		{
			head2->data = head2->data + carry;
			if(head2->data > 9)
			{
				head2->data%=10;
				head2->next = add(head, head2->next, 1);
				return head2;
			}
			else
				return head2;
		}
		else
		{
			head->data = head->data + head2->data + carry;
			if(head->data > 9)
			{
				head->data%=10;
				head->next = add(head->next, head2->next, 1);
				return head;
			}
			else
			{
				head->next = add(head->next, head2->next, 0);
				return head;
			}
		}
	}
	else
	{
		if(carry == 1)
			return insert(head, 1);
		else
			return head;
	}
}

int main()
{
	node *head = NULL,*head2 = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 1);
	curr = insert(curr->next, 0);
	curr = insert(curr->next, 0);
	
	curr = insert(head2, 2);
	curr = insert(curr->next, 9);
	curr = insert(curr->next, 9);
	curr = insert(curr->next, 9);
	head = add(head, head2, 0);
	print(head);
	return 0;
}




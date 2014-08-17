#include <iostream>
using namespace std;
//Check if identical
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

bool identical(node* head1, node* head2)
{
	node *head = NULL, *curr=NULL;
	while(head1 != NULL || head2 != NULL)
	{
		if(head1 == NULL || head2 == NULL)
			return false;
		else
		{
			if(head1->data == head2->data)
			{
				bool id = identical(head1->next, head2->next);
				return (true && id);
			}
			else 
				return false;
		}
	}
	return true;;
}

int main()
{
	node* head = NULL, *head1 = NULL, *head2 = NULL, *curr1 = NULL, *curr2 = NULL;
	curr1 = insert(head1, 1);
	curr1 = insert(curr1->next, 3);
	curr1 = insert(curr1->next, 4);
	curr1 = insert(curr1->next, 6);
	
	curr2 = insert(head2, 1);
	curr2 = insert(curr2->next, 3);
	curr2 = insert(curr2->next, 4);
	curr2 = insert(curr2->next, 6);
	bool id = identical(head1, head2);
	cout<<id<<endl;
	return 0;
}




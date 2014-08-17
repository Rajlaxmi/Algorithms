#include <iostream>
using namespace std;
//Merge two sorted linked lists
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

node* merge(node* head1, node* head2)
{
	node *head = NULL, *curr=NULL;
	while(head1 != NULL || head2 != NULL)
	{
		if(head1 == NULL)
			return head2;
		else if(head2 == NULL)
			return head1;
		else
		{
			if(head1->data == head2->data)
			{
				node* temp = merge(head1->next, head2->next);
				if(curr == NULL)
					curr = insert(head, head1->data);
				else
					curr = insert(curr->next, head1->data);
				curr = insert(curr->next, head2->data);
				curr->next = temp;
				return head;
			}
			else if(head1->data < head2->data)
			{
				node* temp = merge(head1->next, head2);
				if(curr == NULL)
					curr = insert(head, head1->data);
				else
					curr = insert(curr->next, head1->data);
				curr->next = temp;
				return curr;
			}
			else
			{
				node* temp = merge(head1, head2->next);
				if(curr == NULL)
					curr = insert(head, head2->data);
				else
					curr = insert(curr->next, head2->data);
				curr->next = temp;
				return curr;
			}
		}
	}
	return head;
}

int main()
{
	node* head = NULL, *head1 = NULL, *head2 = NULL, *curr1 = NULL, *curr2 = NULL;
	curr1 = insert(head1, 2);
	curr1 = insert(curr1->next, 3);
	curr1 = insert(curr1->next, 5);
	curr1 = insert(curr1->next, 6);
	
	curr2 = insert(head2, 1);
	curr2 = insert(curr2->next, 3);
	curr2 = insert(curr2->next, 4);
	curr2 = insert(curr2->next, 6);
	head = merge(head1, head2);
	print(head);
	return 0;
}



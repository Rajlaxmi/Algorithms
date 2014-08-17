#include <iostream>
using namespace std;
//intersection of two lists
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

node* intersection(node* head1, node* head2)
{
	node* head = NULL,  *curr = NULL;
	while(head1 != NULL && head2 != NULL)
	{
		if(head1 == NULL || head2 == NULL)
			return head;
		else
		{
			if(head1->data == head2->data)
			{
				if(curr == NULL)
					curr = insert(head, head1->data);
				else
					curr = insert(curr->next, head1->data);
				head1 = head1->next;
				head2 = head2->next;
			}
			else if(head1->data < head2->data)
				head1 = head1->next;
			else
				head2 = head2->next;
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
	head = intersection(head1, head2);
	print(head);
	return 0;
}



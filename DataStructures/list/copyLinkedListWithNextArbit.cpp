#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* arbit;
};

node* insert(node* &curr, int data)
{
	curr = new node;
	curr->data = data;
	curr->next = NULL;
	curr->arbit = NULL;
	return curr;
}

node* copy(node* head)
{
	node* curr = head;
	while(curr != NULL)
	{
		node* temp = new node;
		temp->data = curr->data;
		temp->next = curr->next;
		curr->next = temp;
		curr = curr->next->next;
	}
	
	curr = head;
	while(curr != NULL)
	{
		if(curr->arbit == NULL)
			(curr->next)->arbit = (curr->arbit)->next;
		else
			(curr->next)->arbit = NULL;
		curr = curr->next;
	}
	node* head2 = head->next, *curr2 = head2;
	curr = head;
	while(curr != NULL)
	{
		curr2->next = curr->next;
		curr2 = curr2->next;
		curr2-
	}
}

void printN(node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
void printA(node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->arbit;
	}
	cout<<endl;
}

int main()
{
	node *head = NULL, *curr = NULL;
	curr = insert(head, 1);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr = insert(curr->next, 5);
	
	head->arbit = head->next->next;
	(head->next)->arbit = (((head->next)->next)->next)->next;
	((head->next)->next)->arbit = head->next;
	(((head->next)->next)->next)->arbit = NULL;
	((((head->next)->next)->next)->next)->arbit = (((head->next)->next)->next);
	
	printN(head);
	printA(head);
	
}

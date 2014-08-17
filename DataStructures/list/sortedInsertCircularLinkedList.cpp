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
	node* temp = head;
	cout<<head->data<<endl;
	head = head->next;
	while(head!=temp)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
}

node* insertSort(node* head, int data)
{
	if(head == NULL)
	{
		head = new node;
		head->data = data;
		head->next = head;
		return head;
	}
	else if(head->data >= data)
	{
		node* temp = new node;
		temp->data = data;
		temp->next = head;
		node* curr = head->next;
		while(curr->data < data && curr->next != head)
			curr = curr->next;
		curr->next = temp;
		return temp;
	}
	else
	{
		node* curr = head;
		while((curr->next)->data < data && curr->next != head)
			curr = curr->next;
		node* temp = new node;
		temp->data = data;
		temp->next = curr->next;
		curr->next = temp;
		return head;
	}

	
}

int main()
{
	node *head = NULL,*head2 = NULL, *curr = NULL;
	head = insertSort(head, 3);
	head = insertSort(head, 1);
	head = insertSort(head, 6);
	head = insertSort(head, 2);
	head = insertSort(head, 5);
	head = insertSort(head, 4);
	print(head);
	return 0;
}




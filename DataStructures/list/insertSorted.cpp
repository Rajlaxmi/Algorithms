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

void insertSorted(node* &curr, int data)
{
	if(curr == NULL)
	{
		curr = new node;
		curr->data = data;
		curr->next = NULL;
	}
	else if(curr->next == NULL && curr->data >= data)
	{
		node* temp = curr;
		curr = new node;
		curr->data = data;
		curr->next = temp;
	}
	else if((curr->next)->data < data)
		insertSorted(curr->next , data);
	else
	{
		node* temp = curr->next;
		curr->next = new node;
		curr->next->data = data;
		curr->next->next = temp;
	}
}


int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 5);
	insertSorted(head, 4);
	print(head);
	return 0;
}

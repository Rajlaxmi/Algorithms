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
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void deleteList(node* &head)
{
	node* temp = NULL;
	while(head!=NULL)
	{
		temp = head;
		delete head;
		head = head->next;
	}
}


int main()
{
	node *head=NULL, *curr=NULL;
	curr = insert(head , 2);
	curr = insert(curr->next , 3);
	curr = insert(curr->next , 4);
	curr = insert(curr->next , 5);
	//print(head);
	deleteList(head);
	//print(head);
	return 0;
}


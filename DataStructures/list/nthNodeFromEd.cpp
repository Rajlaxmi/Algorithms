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

void printnth(node* head, int n)
{
	node *slow = head, *fast=head;
	int x = n-1;
	while(x>0 && fast!=NULL)
	{
		fast = fast->next;
		x--;
	}
	if(fast!=NULL)
		fast = fast->next;
	else
	{
		cout<<"No nth element"<<endl;
		return;
	}
		
	while(fast!=NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	if(slow!=NULL)
		cout<<slow->data<<endl;
}

int main()
{
	node *head=NULL, *curr=NULL;
	curr = insert(head , 2);
	curr = insert(curr->next , 3);
	curr = insert(curr->next , 4);
	curr = insert(curr->next , 5);
	//print(head);
	printnth(head, 1);
	return 0;
}

#include <iostream>
using namespace std;
//http://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/

struct node
{
	int data;
	node* next;
};

node* insert(node* &head, int data)
{
	head = new node;
	head->data = data;
	head->next = NULL;
	return head;
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

node* reverseK(node* head, int k)
{
	node* curr = head, *prev = NULL;
	if(k == 1)
		return head;
	k--;
	while(curr!= NULL && k>0)
	{
		curr = curr->next;
		prev = curr;
		k--;
	}
	if(curr != NULL)
	{
		node* nxt = head->next;
		head->next = reverseK(curr->next, k);
		curr->next = nxt;
		prev->next = head;
		return curr;
	}
	else
		return head;
}

int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head, 1);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr = insert(curr->next, 5);
	print(head);
	head = reverseK(head, 3);
	print(head);
	return 0;
}


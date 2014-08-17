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

node* pairwise(node* &head)
{
	if(head == NULL || head->next == NULL)
		return head;
	else
	{
		node* rest = pairwise((head->next)->next);
		node* second = head->next;
		second->next = head;
		head->next = rest;
		return second;
	}
}

int main()
{
	node *head=NULL, *curr=NULL;
	curr = insert(head,1);
	curr = insert(curr->next,2);
	curr = insert(curr->next,3);
	curr = insert(curr->next,4);
	curr = insert(curr->next,5);
	print(head);
	node* swap = pairwise(head);
	print(swap);
	return 0;
}

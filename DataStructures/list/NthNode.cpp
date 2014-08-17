#include <iostream>
using namespace std;
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

int nTh(node* head, int n)
{
	n--;
	while(head!=NULL && n>0)
	{
		head = head->next;
		n--;
	}
	if(n == 0 && head != NULL)
		return head->data;
	else
		return -1;
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
	cout<<nTh(head,2)<<endl;
	return 0;
}

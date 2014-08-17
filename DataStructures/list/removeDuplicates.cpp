#include <iostream>
using namespace std;
//http://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

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

node* removeDup(node* head)
{
	node* curr=head, *prev=NULL;
	map<int, bool> nums;
	while(curr!=NULL)
	{
		
	}
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
	head = removeDup(head);
	print(head);
	return 0;
}



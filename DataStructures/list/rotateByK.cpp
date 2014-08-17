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

node* rotate(node* head, int k)
{
	node* curr = head;
	while(curr!=NULL && --k>0 )
		curr = curr->next;

	if(curr == NULL)
	{
		cout<<"K elements not there"<<endl;
		return head;
	}
	else
	{
		node* last = curr;
		while(last->next != NULL)
			last = last->next;
			
		last->next = head;
		node* temp = curr->next;
		curr->next = NULL;
		return temp;
	}
}

int main()
{
	node *head = NULL, *curr = NULL;
	curr = insert(head, 1);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	head = rotate(head, 4);
	print(head);
	return 0;
}

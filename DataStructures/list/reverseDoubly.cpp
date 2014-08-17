#include <iostream>
using namespace std;
struct node
{
	int data;
	node* prev;
	node* next;
};

node* insert(node* &curr, int data, node* prev)
{
	curr = new node;
	curr->data = data;
	curr->prev = prev;
	curr->next = NULL;
	return curr;
}

void print(node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

node* reverse(node* head,node* &head2)
{
	if(head == NULL)
		return head;
	else if(head->next == NULL)
	{
		head->prev = NULL;
		head2 = head;
		return head;
	}
	else
	{
		node* nxt = reverse(head->next, head2);
		nxt->next = head;
		head->prev = nxt;
		head->next = NULL;
		return head;
	}
}

int main()
{
	node* head=NULL, *curr=NULL, *head2=NULL;
	curr = insert(head, 1, NULL);
	curr = insert(curr->next, 2, curr);
	curr = insert(curr->next, 3, curr);
	curr = insert(curr->next, 4, curr);
	print(head);
	reverse(head, head2);
	print(head2);
	return 0;
}

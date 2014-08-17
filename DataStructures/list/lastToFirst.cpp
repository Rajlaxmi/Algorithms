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

node* lastTofirst(node* &head)
{
	if(head == NULL || head->next==NULL)
		return head;
	else
	{
		node* prev = head, *temp = head->next;
		while(temp->next != NULL)
		{
			prev = prev->next;
			temp = temp->next;
		}
		temp->next = head;
		prev->next = NULL;
		return temp;
	}
}

int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	head = lastTofirst(head);
	print(head);
	return 0;
}


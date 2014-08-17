#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

node* insert(int a, node* &curr)
{
	curr = new node;
	curr->data = a;
	curr->next = NULL;
	return curr;
}

void print(node* head)
{
	node* curr = head;
	while(curr != NULL)
	{
		cout<<curr->data<<endl;
		curr = curr->next;
	}
}

int getNth(node* head, int n)
{
	int dt;
	while(n-->0)
	{
		if(head == NULL)
		{
			cout<<"List size is less than "<<n<<endl;
			return 0;
		}
		dt = head->data;
		head = head->next;
	}
	cout<<"Nth is "<<dt<<endl;
}

int main()
{
	node* head = NULL;
	node* curr = NULL;
	curr = insert(2, head);
	curr = insert(5, curr->next);
	curr = insert(7, curr->next);
	curr = insert(8, curr->next);
	getNth(head, 3);
	print(head);
	return 0;
}


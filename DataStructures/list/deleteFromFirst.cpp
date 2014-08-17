#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

node* insert(node*& curr, int data)
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

int main()
{
	node *head=NULL, *curr = NULL;
	
	curr = insert(curr ,2);
	head = curr;
	//curr = curr->next; /// Dont do this... because it creates a copy and curr->next is where next point to not it's copy
	curr = insert(curr->next ,3);
	//curr = curr->next;
	curr = insert(curr->next ,4);
	print(head);
	return 0;
}

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

void print(node* curr)
{
	while(curr!=NULL)
	{
		cout<<curr->data<<endl;
		curr = curr->next;
	}
}
int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head , 1);
	curr = insert(curr->next , 3);
	curr = insert(curr->next , 5);
	curr = insert(curr->next , 2);
	print(head);
	return 0;
}

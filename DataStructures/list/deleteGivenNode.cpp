#include <iostream>
#include <cstdio>
#include <cstdlib>
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
		cout<<head->data<<" "<<&(head->next)<<endl;
		head = head->next;
	}
	cout<<"!!!!!"<<endl;
}

void deleteNode(node* &curr)
{
	if(curr!=NULL)
	{
		node* currnxt = curr->next;
		if(currnxt == NULL)
			curr = NULL;
		else
		{
			curr->data = currnxt->data;
			curr->next = currnxt->next;
			free(currnxt);
		}
	}
}

int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	print(head);
	deleteNode(head->next->next);
	print(head);
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//Delete nodes which have a greater value on right side
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

node* greaterRight(node* curr)
{
	if(curr == NULL || curr->next == NULL)
		return curr;
	else
	{
		if(curr->next->data > curr->data)
		{
			curr->data = curr->next->data;
			node *temp = curr->next;
			curr->next = greaterRight(curr->next->next);
			free(temp);
			return curr;
		}
		else
			greaterRight(curr->next);
	}
}

node* greaterRight2(node* prev, node* curr)
{
	if(curr == NULL || curr->next == NULL)
		return curr;
	else if(prev == NULL)
	{
		if(curr->next->data > curr->data)
		{
			node* temp = curr;
			curr = curr->next;
			free(temp);
			curr = greaterRight2(prev, curr);
			return curr;
		}
		else
		{
			greaterRight2(curr, curr->next);
			return curr;
		}
	}
	else
	{
		if(curr->next->data > curr->data)
		{
			node* temp = curr;
			prev->next = prev->next->next;
			free(temp);
			curr = prev->next;
			greaterRight2(curr, curr->next);
			return curr;
		}
		else
		{
			greaterRight2(curr, curr->next);
			return curr;
		}
	}
}


int main()
{
	node *head = NULL,*curr = NULL;
	curr = insert(head, 12);
	curr = insert(curr->next, 15);
	curr = insert(curr->next, 10);
	curr = insert(curr->next, 11);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 3);
	head = greaterRight2(NULL, head);
	print(head);
	return 0;
}





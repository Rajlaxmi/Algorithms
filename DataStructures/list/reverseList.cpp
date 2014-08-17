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

node* reverse(node* curr, node** head)
{
	if(curr == NULL || curr->next == NULL)
	{
		*head = curr;
		return curr;
	}
	else
	{
		node* &temp = curr;
		if(curr->next->next != NULL)
		{
			node* last = reverse(curr->next->next, head);
			last->next = curr->next;
			(curr->next)->next = curr;
			curr->next = NULL;
			return curr;
		}
		else
		{
			*head = curr->next;
			(curr->next)->next = curr;
			curr->next = NULL;
			return curr;
		}
	}
}

node* reverse2(node* curr, node** head)
{
	if(curr == NULL || curr->next == NULL)
	{
		*head = curr;
		return curr;
	}
	else
	{
		node* last = reverse2(curr->next ,head);
		last->next = curr;
		curr->next = NULL;
		return curr;
	}
}

int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr = insert(curr->next, 5);
	//print(head);
	//reverse(head,&head);
	reverse2(head, &head);
	print(head);
	return 0;
}

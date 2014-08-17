#include <iostream>
using namespace std;
//Reverse a Linked List in groups of given size
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
	if(head == NULL)
		return NULL;
	else
	{
		node* 
	}
}

node* reversek(node* head, int k)
{
	if(head == NULL)
		return head;
	else
	{
		node *curr = head, *temp, *temp2;
		while(curr!=NULL && --k>0)
			curr = curr->next;
			
		if(curr!=NULL)
			temp = reversek(curr->next);
		else
			temp = NULL;
		curr->next = NULL;
		temp2 = reverse(head, head);
		
		curr = temp2;
		while(curr->next!=NULL)
			curr = curr->next;
		curr->next = temp;
		
		return temp2;
	}
}


int main()
{
	int k = 2;
	node *head = NULL,*curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 7);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 7);
	curr = insert(curr->next, 1);
	head = reversek(head, k);
	print(head);
	return 0;
}




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

node* pairwiseSwap(node* head)
{
	if(head == NULL || head->next==NULL)
		return head;
	else
	{
		int temp = head->data;
		head->data = head->next->data;
		head->next->data = temp;
		head->next->next = pairwiseSwap(head->next->next);
		return head;
	}
}
node* pairwiseSwap2(node* &head)
{
	if(head == NULL || head->next==NULL)
		return head;
	else
	{
		//int temp = head->data;
		node* temp2 = head->next->next;
		head->next->next = head;
		node* temp = head->next;
		head->next = pairwiseSwap2(temp2);
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
	head = pairwiseSwap2(head);
	print(head);
	return 0;
}


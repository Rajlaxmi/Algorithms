#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//Merge Sort for Linked Lists
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

node* getMid(node* head)
{
	if(head == NULL || head->next)
		return head;
	else
	{
		node *fast = head->next, *slow = head;
		while(fast!=NULL || fast->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
}

node* merge(node* head1, node* head2)
{
	while(head1!=NULL || head2!=NULL)
	{
		if(head1 == NULL)
			return head2;
		else if(head2 == NULL)
			return head1;
		else
		{
			if(head1->data == head2->data)
			{
				node* temp = merge(head1->next, head2->next);
				head1->next = head2;
				head2->next = temp;
				return head1;
			}
			else if(head1->data < head2->data)
			{
				node* temp = merge(head1->next, head2);
				head1->next = temp;
				return head1;
			}
			else
			{
				node* temp = merge(head1, head2->next);
				head2->next = temp;
				return head2;
			}
		}
	}
	return NULL;
}

node* mergeSort(node* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	else
	{
		node* mid = getMid(head);
		node* head2 = mid->next;
		mid->next = NULL;
		return merge(mergeSort(head), mergeSort(head2));
	}
}

int main()
{
	node *head = NULL,*curr = NULL;
	curr = insert(head, 2);
	curr = insert(curr->next, 7);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 7);
	curr = insert(curr->next, 1);
	head = mergeSort(head);
	print(head);
	return 0;
}




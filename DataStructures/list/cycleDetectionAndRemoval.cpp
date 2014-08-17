#include <iostream>
using namespace std;
//Detect Cycle and Remove it
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

node* cycle(node *head)
{
	node* slow = head, *fast = head->next;
	while(fast!=NULL && fast->next!=NULL && fast!=slow)
	{
		//cout<<slow->data<<" "<<fast->data<<endl;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast!=NULL || fast->next!=NULL)
	{
		cout<<"Loop detected"<<endl;
		int k = 1;
		node* temp = fast;
		fast = fast->next;
		while(fast!=temp)
		{
			fast = fast->next;
			k++;
		}
		cout<<"Number of elements in loop: "<<k<<endl;
		
		int n = k;
		temp = head;
		while(n-- > 0)
		{
			head = head->next;
		}
		node* temp2 = head;
		while(temp->next!=temp2->next)
		{
			temp = temp->next;
			temp2 = temp2->next;
		}
		//temp2 is in loop so
		temp2->next = NULL;
	}
	else
	{
		cout<<"No Loop detected"<<endl;
		return head;
	}
}

int main()
{
	node *head = NULL,*curr = NULL;
	curr = insert(head, 1);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr = insert(curr->next, 5);
	curr = insert(curr->next, 6);
	curr = insert(curr->next, 7);
	curr->next = head->next->next;
	cycle(head);
	print(head);
	return 0;
}





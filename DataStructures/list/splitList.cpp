#include <iostream>
#include <utility>
using namespace std;
//http://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/

struct node
{
	int data;
	node* next;
};

node* insert(node* &head, int data)
{
	head = new node;
	head->data = data;
	head->next = NULL;
	return head;
}

void print(node* head)
{
	node* curr = head;
	if(curr != NULL)
	{
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	while(curr!=NULL && curr!=head)
	{
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

pair<node* ,node*> split(node* head)
{
	node* head2 = NULL;
	if(head->next == NULL)
		return make_pair(head, head2); //Important
	else
	{
		node* slow=head, *fast = head->next;
		while(fast->next!=head && fast->next->next != head)
		{
			slow = slow->next;
			fast = (fast->next)->next;
		}
		//slow->next = head;
		if(fast->next == head)
			fast->next = slow->next;
		else
			fast->next->next = slow->next;
		head2 = slow->next;
		slow->next = head;
		return make_pair(head, head2);
	}
}

int main()
{
	node* head = NULL, *curr = NULL;
	curr = insert(head, 1);
	curr = insert(curr->next, 2);
	curr = insert(curr->next, 3);
	curr = insert(curr->next, 4);
	curr->next = head;
	print(head);
	pair<node*,node*> hd = split(head);
	print(hd.first);
	print(hd.second);
	return 0;
}



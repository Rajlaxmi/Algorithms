#include <iostream>
#include <algorithm>
#include <vector>
//www.geeksforgeeks.org/flattening-a-linked-list/index.html
using namespace std;

/*
 * Imp: Node has a < defined on its data
 * Otherwise on sort good to use myfunction
 * sort by default uses < to sort.
 * So for reverse use >
 * back returns last element
 * pop_back pops last element
 */
struct node
{
	int data;
	node* next;
	node* down;
};

node* insert(node* &curr, int data)
{
	curr = new node;
	curr->data = data;
	curr->next = NULL;
	curr->down = NULL;
	return curr;
}

void print(node* head)
{
	while(head->next!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

bool comp(node* a, node* b)
{
	return a->data > b->data;
}

node* flatten(node* head)
{
	vector<node*> tosort;
	tosort.push_back(head);
	node* head2 = NULL, *curr = NULL;
	while(!tosort.empty())
	{
		sort(tosort.begin(), tosort.end(), comp); // sort in reverse order
		node* top = tosort.back();
		tosort.pop_back(); 
		
		if(head2 == NULL)
			curr = insert(head2, top->data);
		else
			curr = insert(curr->next, top->data);
			
		if(top->next != NULL)
			tosort.push_back(top->next);
		if(top->down != NULL)
			tosort.push_back(top->down);
	}
	return head2;
}

int main()
{
	node *head = NULL, *curr = NULL;
	curr = insert(head, 5);
	curr = insert(curr->down, 7);
	curr = insert(curr->down, 8);
	curr = insert(curr->down, 30);
	
	curr = insert(head->next, 10);
	curr = insert(curr->down, 20);
	
	curr = insert(head->next->next, 19);
	curr = insert(curr->down, 22);
	curr = insert(curr->down, 50);
	
	curr = insert(head->next->next->next, 28);
	curr = insert(curr->down, 35);
	curr = insert(curr->down, 40);
	curr = insert(curr->down, 45);
	
	head = flatten(head);
	print(head);
	return 0;
}

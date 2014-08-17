#include <iostream>
#include <stack>
using namespace std;

stack<int> insert(stack<int> st, int a)
{
	if(st.size() == 0)
	{
		st.push(a);
		return st;
	}
	else
	{
		int x = st.top();
		st.pop();
		st = insert(st, a);
		st.push(x);
		return st;
	}
}

stack<int> reverse(stack<int> st)
{
	if(st.size() == 1)
		return st;
	else
	{
		//cout<<"!"<<endl;
		int x = st.top();
		st.pop();
		st  = reverse(st);
		st = insert(st, x);
		return st;
	}
}

void print(stack<int> st)
{
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main()
{
	stack<int> st;
	int n,x;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		st.push(x);
	}
	
	st = reverse(st);
	print(st);
	return 0;
}


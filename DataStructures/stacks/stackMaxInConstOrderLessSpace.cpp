#include <iostream>
#include <stack>
#include <climits>
using namespace std;
class stackMax
{
	stack<int> st;
	stack<int> max;
public:
	void push(int a)
	{
		if(max.empty() || a >= max.top())
		{
			st.push(a);
			max.push(a);
		}
		else
			st.push(a);
	}
	void pop()
	{
		if(st.top() == max.top())
			max.pop();
		st.pop();
	}
	int top()
	{
		return st.top();
	}
	int maxVal()
	{
		return max.top();
	}
	
	void print()
	{
		while(!st.empty())
		{
			cout<<st.top()<<" "<<max.top()<<endl;
			if(st.top() == max.top())
				max.pop();
			st.pop();
		}
		cout<<endl;
	}
};

int main()
{
	stackMax st;
	int n,x;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		st.push(x);
	}
	
	st.print();
	
	return 0;
}



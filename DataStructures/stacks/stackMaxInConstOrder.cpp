#include <iostream>
#include <stack>
#include <climits>
using namespace std;
class stackMax
{
	stack<int> st;
	stack<int> max;
	int maxm = INT_MIN;
public:
	void push(int a)
	{
		if(a > maxm)
			maxm = a;
		st.push(a);
		max.push(maxm);
	}
	void pop()
	{
		st.pop();
		max.pop();
		if(!max.empty())
			maxm = max.top();
		else
			maxm = INT_MIN;
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
			st.pop();
			max.pop();
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


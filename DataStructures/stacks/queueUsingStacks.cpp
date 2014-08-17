#include <iostream>
#include <stack>
using namespace std;

class queue
{
	stack<int> std; //stack in descending order
	stack<int> sta; //stack in ascending order
public:
	bool empty()
	{
		return std.empty();
	}
	int size()
	{
		return std.size();
	}
	int front()
	{
		if(!std.empty())
		{
			int x,ret,sz;
			for(int i=0; i<std.size()-1; i++)
			{
				x = std.top();
				std.pop();
				sta.push(x);
			}
			ret = std.top();
			
			sz = sta.size();
			for(int i=0; i<sz; i++)
			{
				x = sta.top();
				sta.pop();
				std.push(x);
			}
			
			return ret;
			
		}
		else
		{
			cout<<"Empty Queue!"<<endl;
			return 0;
		}
		
	}
	int back()
	{
		if(!std.empty())
			return std.top();
		else
		{
			cout<<"Empty Queue!"<<endl;
			return 0;
		}
	}
	void push(int a)
	{
		std.push(a);
	}
	void pop()
	{
		if(!std.empty())
		{
			int x,sz;
			for(int i=0; i<std.size()-1; i++)
			{
				x = std.top();
				std.pop();
				sta.push(x);
			}
			std.pop();
			
			sz = sta.size();
			for(int i=0; i<sz; i++)
			{
				x = sta.top();
				sta.pop();
				std.push(x);
			}
			
		}
		else
		{
			cout<<"Empty Queue!"<<endl;
		}
	}
};

int main()
{
	queue myq;
	myq.push(2);
	myq.push(3);
	cout<<myq.front()<<endl;
	cout<<myq.size()<<endl;
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;
class stack
{
	queue<int> qas; //ascending queue
	queue<int> qad; //decending queue
public:
	bool empty()
	{
		return qas.empty();
	}
	int size()
	{
		return qas.size();
	}
	int top()
	{
		if(!qas.empty())
		{
			int x,ret,sz;
			for(int i=0; i<qas.size()-1; i++)
			{
				x = qas.front();
				qas.pop();
				qad.push(x);
			}
			ret = qas.front();
			qas.pop();
			qad.push(ret);
			
			sz = qad.size();
			for(int i=0; i<sz; i++)
			{
				x = qad.front();
				qad.pop();
				qas.push(x);
			}
			return ret;
		}
		else
		{
			cout<<"Empty Stack!"<<endl;
			return 0;
		}
		
	}
	void push(int a)
	{
		qas.push(a);
	}
	void pop()
	{
		if(!qas.empty())
		{
			int x,sz;
			for(int i=0; i<qas.size()-1; i++)
			{
				x = qas.front();
				qas.pop();
				qad.push(x);
			}
			qas.pop();
			
			sz = qad.size();
			for(int i=0; i<sz; i++)
			{
				x = qad.front();
				qad.pop();
				qas.push(x);
			}
		}
		else
		{
			cout<<"Empty Stack!"<<endl;
		}
	}
};
int main()
{
	stack st;
	st.push(2);
	st.push(3);
	cout<<st.top()<<endl;
	cout<<st.size()<<endl;
	return 0;
}

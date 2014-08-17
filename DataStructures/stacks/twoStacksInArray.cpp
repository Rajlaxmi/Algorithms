#include <iostream>
#define N 100 //size of array
using namespace std;

class twoStacks
{
	int arr[N];
	int top1 = -1, top2=N;
public:
	void push1(int a)
	{
		if(top1<top2)
		{
			top1++;
			arr[top1] = a;
		}
		else
			cout<<"No space!"<<endl;
	}
	void push2(int a)
	{
		if(top1<top2)
		{
			top2--;
			arr[top2] = a;
		}
		else
			cout<<"No space!"<<endl;
	}
	void pop1()
	{
		if(top1 >= 0)
			top1--;
		else
			cout<<"No element!"<<endl;
	}
	void pop2()
	{
		if(top2 <= N)
			top2++;
		else
			cout<<"No element!"<<endl;
	}
	int tp1()
	{
		return arr[top1];
	}
	int tp2()
	{
		return arr[top2];
	}
	int size1()
	{
		return top1+1;
	}
	int size2()
	{
		return (N-top2);
	}
	bool empty1()
	{
		if(size1() == 0)
			return true;
		else
			return false;
	}
	bool empty2()
	{
		if(size2() == 0)
			return true;
		else
			return false;
	}
};

int main()
{
	
	return 0;
}


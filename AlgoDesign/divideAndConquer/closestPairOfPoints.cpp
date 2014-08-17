#include <iostream>
#include <utility>
using namespace std;

pair<pair<int,int>, pair<int,int>> closest(int* arr, int l, int h)
{
	if(l>h)
	{
		if(h-l == 1)
			return make_pair(arr[l], arr[h]);
		else
		{
			int m = (l+h)/2;
			if()
		}
	}
	else
	{
		//cant find closest in less than 1 point
		cout<<"Invalid!!"<<endl;
	}
}

int main()
{
	int n,x,y;
	cin>>n;
	pair<int,int> arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>x;
		cin>>y;
		arr[i] = make_pair(x,y);
	}
	pair<pair<int,int>, pair<int,int>> cl = closest(arr, 0, n-1);
	cout<<(cl.first).first<<" "<<(cl.first).second<<endl;
	cout<<(cl.second).first<<" "<<(cl.second).second<<endl;
}

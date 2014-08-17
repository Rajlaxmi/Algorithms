#include <iostream>
using namespace std;

int pow(int x,int n)
{
	if(n == 0)
		return 1;
	else if(n%2 == 0)
		return pow(x*x, n/2);
	else
		return x*pow(x, (n-1));
}

int main()
{
	int n,x;
	
	cin>>x;
	cin>>n;
	
	cout<<pow(x,n)<<endl;
		
	return 0;
}


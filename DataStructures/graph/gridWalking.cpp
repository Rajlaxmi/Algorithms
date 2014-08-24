#include <iostream>
using namespace std;
int x[11];
int main()
{
	int t, n, m, i, mnew, mv, mn, mx;
	while(t--)
	{
		cin>>n>>m;
		mnew = m; 
		mv = 0;
		for(i=0; i<n; i++)
			cin>>x[i];
			
		for(i=0; i<n; i++) {
			cin>>dim;
			mn = ((x[i]-m)>=0)?m:x[i];
			mx = ((x[i]+m)<dim)?m:dim-x[i];
			mnew+=mn;
			mv+=(mx+mn);
		}
		cout<<binCoeff(mv, mnew); //C(n, r)
	}
}

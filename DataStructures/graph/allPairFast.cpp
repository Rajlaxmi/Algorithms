#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define loop(i, n) for(i=0; i<n; i++)
#define pb push_back
#define mx 200
using namespace std;
vector<vector<int> > W, L, Lnew, L1;

void print(vector<vector<int> > L, int n)
{
	int i, j;
	loop(i, n) {
		loop(j, n) {
			if(L[i][j] == mx)
				cout<<200<<" ";
			else
				cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void buildGraph()
{
	W[0].pb(0); W[0].pb(3); W[0].pb(8); W[0].pb(mx); W[0].pb(-4); 
	W[1].pb(mx); W[1].pb(0); W[1].pb(mx); W[1].pb(1); W[1].pb(7); 
	W[2].pb(mx); W[2].pb(4); W[2].pb(0); W[2].pb(mx); W[2].pb(mx); 
	W[3].pb(2); W[3].pb(mx); W[3].pb(-5); W[3].pb(0); W[3].pb(mx); 
	W[4].pb(mx); W[4].pb(mx); W[4].pb(mx); W[4].pb(6); W[4].pb(0); 
	//cout<<W.size()<<" "<<W[0].size()<<" "<<W[1].size()<<" "<<W[2].size()<<" "<<W[3].size()<<" "<<W[4].size()<<endl;
}

void extendShortestPath(vector<vector<int> > A, vector<vector<int> > B, int n) //for slow
{
	int i, j, k, ans;
	loop(i, n) {
		loop(j, n) {
			ans = INT_MAX;
			loop(k, n) {
				ans = min(ans, A[i][k] + B[k][j]);
			}
			Lnew[i][j] = ans;
		}
	}
	print(Lnew, n);
	L = Lnew;
}

void fastAllPairShortest(int x, int n)
{
	//L .. to find L^n-1
	if(x == 1)
		L = L1;
	while(x > 0) {
		if(x%2 == 1) {
			fastAllPairShortest(x-1, n);
			extendShortestPath(L, L1, n);
			x = x-1;
		}
		else {
			fastAllPairShortest(x/2, n);
			extendShortestPath(L, L, n);
			x/=2;
		}
	}
}

int main()
{
	int n, x, i, j;
	//cin>>n;
	n = 5;
	W.resize(n);
	L.resize(n);
	buildGraph();
	/*loop(i, n) {
		loop(j, n) {
			cin>>x;
			W[i].pb(j);
		}
	}*/
	
	//print(W, n);
	L = W;
	Lnew = L;
	L1 = L;
	fastAllPairShortest(n-1, n);
	//print(L, n);
	return 0;
}


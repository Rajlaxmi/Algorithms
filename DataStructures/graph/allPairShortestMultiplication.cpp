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

void extendShortestPath(int n) //for slow
{
	int i, j, k, ans;
	//vector<vector<int> > Lnew = L;
	//Lnew = L;
	loop(i, n) {
		loop(j, n) {
			ans = INT_MAX;
			loop(k, n) {
				
				ans = min(ans, L[i][k] + W[k][j]);
			}
			Lnew[i][j] = ans;
		}
	}
	print(Lnew, n);
	L = Lnew;
	//return Lnew;
}

void slowAllPairShortest(int n)
{
	int i=0;
	loop(i, n-2)
		extendShortestPath(n);
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
	slowAllPairShortest(n);
	//print(L, n);
	return 0;
}

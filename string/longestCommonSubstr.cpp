#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)
using namespace std;

int main()
{
	string str, str1;
	cin>>str>>str1;
	int n = str.length(), m = str1.length(), i, j;
	int dp[m][n];
	i = 0; // index in str
	j = 0; // index in str1
	int s = 0;
	while(i < n && j < m) {
		s = 0;
		if(i-1 >=0 && j-1 >=0) {
			s = dp[j-1][i-1];
		}
		if(str.at(i) == str1.at(j)) {
			s++;
			dp[j][i] = s;
		}
		else
			dp[j][i] = 0;
		//cout<<i<<" "<<j<<" "<<dp[j][i]<<endl;
		i++;
		if(i == n) {
			i = 0;
			j++;
		}
	} 
	int mx = 0, k;
	loop(i, m) {
		loop(j, n) {
			//cout<<dp[i][j]<<" "<<mx<<endl;
			if(mx < dp[i][j]) {
				k = j;
				mx = dp[i][j];
				//cout<<mx<<endl;
			}
		}
	}
	if(mx == 0)
		cout<<"No string matched"<<endl;
	else
		cout<<str1.substr(k-mx+1, mx)<<endl;
	return 0;
}

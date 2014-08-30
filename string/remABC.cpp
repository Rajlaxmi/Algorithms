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
	char str[100];
	cin>>str;
	int n = strlen(str), i=0, j=0;
	
	while(i < n) {
		if(str[i] == 'b')
			i++;
		else if(str[i] == 'a') {
			if(i+1 < n && str[i+1] == 'c') {
				i+=2;
			}
			else {				
				str[j] = str[i];
				j++;
				i++;
			}
		}
		else {
			str[j] = str[i];
			j++;
			i++;
		}
	}
	str[j] = '\0';
	cout<<str<<endl;
	return 0;
}


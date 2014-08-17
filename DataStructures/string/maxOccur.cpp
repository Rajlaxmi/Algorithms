#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>

using namespace std;
int main()
{
	map<char,int> numocc;
	string gvn;
	cin>>gvn;
	
	int maxm = 0;
	for(int i=0; i<gvn.length(); i++)
	{
		if(numocc.find(gvn.at(i)) == numocc.end())
		{
			numocc[gvn.at(i)] = 1;
			maxm = max(maxm, 1);
		}
		else
			maxm = max(maxm, ++numocc[gvn.at(i)]);
	}
	//traverse through map
	map<char,int>::iterator it;
	for(it = numocc.begin(); it!=numocc.end(); it++)
	{
		if(it->second >= maxm)
			cout<<it->first<<endl;
	}
	return 0;
}

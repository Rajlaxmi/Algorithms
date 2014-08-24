//https://www.hackerrank.com/challenges/gem-stones
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int main()
{
	int n, i, j, len, curr, cnt=0, pr=0;
	cin>>n;
	string str;
	getline(cin, str);
	pr = (1<<27) - 1;
	for(i = 0; i < n; i++)
	{
		curr = 0;
		getline(cin, str);
		len = str.length();
		for(j = 0; j < len; j++)
			curr = curr | (1<<(str.at(j)-97));
		pr = pr & curr;
	}
	for(j = 0 ; j<26; j++)
		if((pr>>j & 1) == 1)
			cnt++;
	cout<<cnt<<endl;
}



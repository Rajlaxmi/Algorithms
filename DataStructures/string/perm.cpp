#include <iostream>
#include <cstring>
#include <map>
using namespace std;
bool perm(char* str, char* str1, int size)
{
	map<char, int> mp1, mp2;
	int i=0;
	while(i < size)
	{
		if(mp1.find(str[i]) == mp1.end())
			mp1[str[i]]=1;
		else
			mp1[str[i]]++;
		if(mp2.find(str1[i]) == mp2.end())
			mp2[str1[i]]=1;
		else
			mp2[str1[i]]++;
		i++;
	}
	for(map<char, int>::iterator it=mp1.begin(), it1=mp2.begin(); it != mp1.end() && it1 != mp2.end(); it++, it1++)
	{
		if(!(it->first == it1->first && it->second == it1->second))
			return false;
	}	
	return true;
}
int main()
{
	char str[] = "hi baby :*";
	char str1[] = ":hbi *ayb ";
	int size = strlen(str);
	cout<<perm(str, str1, size)<<endl;
	return 0;
}

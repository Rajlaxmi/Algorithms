#include <iostream>
using namespace std;

void count(char* str, int pos, int cnt)
{
	int mod;
	char sz[100];
	while(cnt > 0)
	{
		mod = cnt%10;
		sz[]
		cnt/=10;
	}
}

void compress(char* str)
{
	int sz = strlen(str);
	char str1[2*sz], *bstr1 = str1, *bstr = str;
	int i=1, cnt=1, j=0;
	while(i < sz)
	{
		if(str[i] != str[i-1])
		{
			str1[j] = str[i-1];
			n = count(str1, j+1, cnt);//no of chars in j
			j+=n;
			cnt = 1;
		}
		else
			cnt++;
		i++;
	}
	int nz = strlen(str1);
	if(nz > sz)
		cout<<bstr<<endl;
	else
		cout<<bstr1<<endl;
}
int main()
{
	char str[] = "aabcccccaaa";
	compress(str);
	return 0;
}

#include <iostream>
using namespace std;
void replace(char *str, int size)
{
	int cnt=0, i=0;
	while(i < size)
	{
		if(str[i] == ' ')
			cnt++;
		i++;
	}
	int nsz=size + 2*cnt, ne=nsz-1, e=size-1;
	while(e > 0)
	{
		if(str[e] == ' ')
		{
			str[ne] = '0';
			str[ne - 1] = '2';
			str[ne - 2] = '%';
			ne-=3;
		}
		else
		{
			str[ne] = str[e];
			ne--;
		}
		cout<<str<<endl;
		e--;
	}
	//cout<<str<<endl;
}

int main()
{
	char str[] = "Mr John Smith    ";
	replace(str, 13);
	return 0;
}

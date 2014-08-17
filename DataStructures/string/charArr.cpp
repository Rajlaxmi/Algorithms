#include <iostream>
using namespace std;
void reverse(char* str, int size)
{
	char *end=str+size-1, *str1=str;
	char c;
	
	int s=0, e=size-1;
	
	while(str < end)
	{
		c = *str;
		*str = *end;
		*end = c;
		//s++;
		//e--;
		str++;
		end--;
	}
	cout<<*str<<" "<<*str1<<" "<<(*str<*str1)<<endl;
	cout<<str1<<endl;
}

int main()
{
	char str[] = "hello world";
	reverse(str, 11);
	return 0;
}

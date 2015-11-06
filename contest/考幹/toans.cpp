#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int a;
	char c[100];
	cin>>c;
	int len=strlen(c);
		
	for(int i=0;i<len/2;++i)
	{
		char t=c[i];
		c[i]=c[len-1-i];
		c[len-1-i]=t;
	}	
	cout << c;
	
	cin>>a;
	return 0;
};

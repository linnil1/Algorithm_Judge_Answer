#include<cstdio>
#include<cstdlib>
#include<cstring>

#include<string>
#include<iostream>
using namespace std;

int main()
{
	int i,j,time;
	string a;
	int al[300];
	for(i='A';i<='Z';++i)
	    al[i]=0;
	//while
	(std::getline(cin,a));
	{
		char test[200];
		cin>>test;
		for(i=0;test[i];++i)
			++al[test[i]];
		for(i=0,j=0;i<a.size();++i)
		    if(a[i]==' ')
				++j;
			else if(al[a[i]])
			{
				--al[a[i]];
				while(j&&j--)
				    putchar(' ');
				putchar(a[i]);
			}
			else break;
		puts("");
	};
	return 0;
};

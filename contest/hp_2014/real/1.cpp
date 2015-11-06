#include<stdio.h>
#include<ctype.h>
#include<string>
using namespace std;
int main()
{
	char c;int r=0;
	freopen("input.txt","r",stdin);	
	while((c=getchar())!=EOF)
	{
		if(isalpha(c))
		{
			r=1;
			putchar(c);
		}
		else if(r)
			puts(""),--r;
	}
	return 0;
}


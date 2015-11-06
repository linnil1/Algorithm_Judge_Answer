#include<stdio.h>

/*
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
*/

/*
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>

#include<cstdlib>
using namespace std;
*/
#define times --time||~scanf("%d",&time)
#define e 15
#define r 30
int main()
{
	int i,j,k,time=1;
	int a,b;
	char c[e][r+5];
	for(i=0;i<e;++i)
	    scanf("%s",c[i]);
	for(i=0;i<e;++i)
	    for(j=0;j<r;++j)
	        if(c[i][j]=='*')
	            for(a=-1;a<=1;++a)
	                if(i+a>=0 && i+a<e)
	                	for(b=-1;b<=1;++b)
	                	    if(j+b>=0 && j+b<r && c[i+a][j+b]!='*')
								if(c[i+a][j+b]=='.')
                                    c[i+a][j+b]='1';
								else
                                    ++c[i+a][j+b];
    for(i=0;i<e;++i)
    {
		c[i][r]='\0';
		printf("%s\n",c[i]);
	};


	/*while(~scanf("%d",&a))
	{

	};
	scanf("%*d");*/
	return 0;
};
/*

*/

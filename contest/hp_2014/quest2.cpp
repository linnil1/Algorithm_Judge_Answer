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
long long int find(long long int a)
{
	long long int b=a,c=0;
	while(b)
	{
	    c=c*10+b%10;
	    b/=10;
	};
	if(a==c)
	    return 0;
	else
	    return a+c;
	
};
int main()
{
	long long int i,j,k,time=1;
	long long int a,b;
	while(~scanf("%lld",&a))
	{
		while(i=find(a))
			a=i;
		printf("%lld\n",a);
	};
	return 0;
};
/*

*/

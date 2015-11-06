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
int main()
{
	int i,j,k,time=1;
	long long int a,b;
	while(~scanf("%lld",&a))
	{
		b=a;
		printf("%lld\n",a);
		while(a>99)
		{
			i=a%10;
			a/=10;
			a-=i;
			printf("%lld\n",a);
		};
		if(a%11)
		    printf("The number %lld is not divisible by 11.\n",b);
		else
			printf("The number %lld is divisible by 11.\n",b);
		
	};
	return 0;
};
/*

2
3 1
5 1 4
1 3 5
5 2
1 1 5 1 5
2 5 5
1 4 5

*/

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
	int a,b;
	while(~scanf("%d",&a))
	{
		b=a;
		for(k=0;k<105;++k)
		{
			i=a/10;
			j=a%10;
			a=i*i+j*j;
			if(a==1)
			    break;
		};
		if(a==1)
			printf("%d is a happy number\n",b);
		else
		    printf("%d is an unhappy number\n",b);

	};
	return 0;
};
/*

*/

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
	double a[1000],b[1000],sum;
	while(~scanf("%d",&k))
	{
		
		for(i=0;i<k;++i)
			scanf("%lf%lf",&a[i],&b[i]);
		a[k]=a[0];b[k]=b[0];sum=0;
		for(i=0;i<k;++i)
		    sum+=a[i]*b[i+1];
        for(i=0;i<k;++i)
		    sum-=b[i]*a[i+1];
		if(sum<0)
		    sum=-sum;
		printf("%.0lf\n",sum/2);

	};
	return 0;
};
/*

*/

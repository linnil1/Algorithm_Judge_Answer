#include<cstdio>
#include<cstdlib>
#include<cstring>


#include<algorithm>
/*
#include<string>
#include<iostream>
using namespace std;
*/


int main()
{
	int i,j,time;
	int n;
	while(~scanf("%d",&n))
	{
		int c[n];
		int x,w,allw=0;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&x,&w);
			c[i]=allw-x;
			allw+=w;
		};
		std::sort(c,c+n);
		int mid=c[n/2],sum=0;
		for(i=0;i<n;++i)
		    sum+=std::abs(mid-c[i]);
		printf("%d\n",sum);
	};
	return 0;
};

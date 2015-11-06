#include<cstdio>
#include<cstdlib>
#include<cstring>
/*
#include<string>
#include<iostream>
using namespace std;
*/
#define M 100
int dp[25][M];
#define M_ax 0x7fffffff
#define tomin(a,b) (a<b?a:b)
int start,tain,away;
int f(int k,int t)
{
	if(k>t)
	    return (k-t)*start+k*tain;
	else
	    return (t-k)*away+k*tain;
};
int main()
{
	int i,j,time;
	int n;
	while(~scanf("%d",&n))
	{
		
		scanf("%d%d%d",&start,&tain,&away);
		
		dp[0][0]=0;
		for(i=1;i<M;++i)
		    dp[0][i]=M_ax;
		for(i=1;i<=n;++i)
		{
			int k;
			scanf("%d",&k);
			for(j=0;j<k;++j)
			    dp[i][j]=M_ax;

			
			for(;k<M;++k)//people
			{
                int min=M_ax;
			    for(j=0;j<M;++j)//people
			    	if(dp[i-1][j]!=M_ax && dp[i-1][j]+f(k,j) < min)
			        	min = dp[i-1][j]+f(k,j);
				dp[i][k]=min;
			};
		};
		/*for(i=0;i<=n;++i,puts(""))
		    for(j=0;j<M;++j)
				printf("%d ",dp[i][j]==M_ax? -1 : dp[i][j]);*/
		
		int min=M_ax;
		
		for(i=0;i<M;++i)
		    min=tomin(min,dp[n][i]);
		printf("%d\n",min);

	};
	return 0;
};

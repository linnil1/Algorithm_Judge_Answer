#include<bits/stdc++.h>
#define lld long long int
//#define yesT
#define M 1000100

void pack(lld *dp,int p,int f,int w)
{
	for(int i=p-w;i>=0;--i)
		if(dp[i]!=-1 && dp[i]+f > dp[i+w])
			dp[i+w] = dp[i] + f;
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,p;
	while(~scanf("%d%d",&n,&p))
	#endif	
	{
		lld dp[p+1];
		std::fill(dp,dp+p+1,0);
		
		while(n--)
		{
			int m,f,w;
			scanf("%d%d%d",&m,&f,&w);
			
			for(int i=0;i<=p&&m;++i)
				
				
				
				
			for(int i=0;i<=p;++i)
				printf("%d ",dp[i]);
			puts("");
			
		}
		printf("%I64d\n",dp[p]);
	};
	return 0;
};
/*
*/

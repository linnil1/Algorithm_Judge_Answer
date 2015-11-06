#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 110
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

int dp[M][M];

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,k;
	while(~scanf("%d%d",&n,&k))
	#endif	
	{
		memset(dp,0,sizeof(dp));
		for(int i=0,x,y;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			++dp[x][y];
		};
		if(k==0)
		{
			puts("0");
			continue;
		}
		int max=INT_MAX;
		for(int i=1;i<M;++i)
			for(int j=1;j<M;++j)
			{
				dp[i][j] += dp[i-1][j] + dp[i][j-1] -dp[i-1][j-1];
				if(dp[i][j]>=k && i*i*j<max)
					max = i*i*j;
			};
					
		printf("%d\n",max*4);
	};
	return 0;
};
/*
*/

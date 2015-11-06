#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 10000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

ll dp[5100][1100];
ll arr[1100];

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int k,n;
		scanf("%d%d",&k,&n);
		k+=8;
		for(int i=0;i<n;++i)
			scanf("%lld",arr+i);
		
		for(int j=1;j<=k;++j)
			dp[n][j] = LLONG_MAX ;
		dp[n][0] = 0 ;
		
		for(int i=n-1;i>=0;--i)
		{
			for(int j=0;j<=k;++j)
				dp[i][j] =	dp[i+1][j];
				
			for(int j=1;j<=k;++j)
				if(i+2<n && dp[i+2][j-1]!=LLONG_MAX && n-i-3*j>=0)
					dp[i][j] = std::min ( dp[i][j] , 
						dp[i][j-1] + (arr[i+1]-arr[i])*(arr[i+1]-arr[i]));
		}
		printf("%lld\n",dp[0][k]);
		
	};
	return 0;
};
/*
*/

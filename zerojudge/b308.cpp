#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 1100
#define MOD 1000000007

int dp[2][M];

void pack(int *dp,int m)
{
	for(int i=M-m;i>=0;--i)
		if(dp[i]!=INT_MAX && dp[i]+1 < dp[i+m] )
			dp[i+m] = dp[i] + 1;
	
}

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
		int money[5]={1,5,10,50,100};
		for(int i=0;i<M;++i)
			dp[0][i] = dp[1][i] = INT_MAX;
		dp[0][0] = dp[1][0] = 0;
		
		for(int i=0;i<5;++i)
		{
			int t;
			scanf("%d",&t);
			while(t--)
				pack(dp[0],money[i]);
		}
		
		/*for(int i=0;i<100;++i)
			printf("%d ",dp[0][i]);
		puts("");*/
		
		
		for(int i=0;i<5;++i)
		{
			int t;
			scanf("%d",&t);
			while(t--)
				pack(dp[1],money[i]);
		}
		
		int need;
		scanf("%d",&need);
		
		int min = INT_MAX,ok=0;
		for(int i=need;i<M;++i)
		{
			if(dp[0][i] != INT_MAX)
				ok=1;
			if(dp[0][i] != INT_MAX && dp[1][i-need] != INT_MAX &&
				dp[1][i-need] < min)
				min = dp[1][i-need] ;
		}
		if(!ok)
			puts("I HAVE MAGIC!");
		else if(min == INT_MAX)
			puts("YOU ARE MAGICIAN!");
		else
			printf("%d\n",min);
		
	};
	return 0;
};
/*
*/

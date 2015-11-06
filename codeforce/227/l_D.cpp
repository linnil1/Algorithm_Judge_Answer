#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 2010
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

double sum;

double p,np;
int n;
double dfs(double now,int a,int t)
{
	if(t==0 || a==n)
	{
		sum+=now*a;
		return 0;
	}
	dfs(now*p,a+1,t-1);
	dfs(now*np,a,t-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int t;
	while(~scanf("%d%lf%d",&n,&p,&t))
	#endif	
	{
		np = 1-p;
		sum = 0;
		
				
		double dp[t+1][n+1];
		for(int j=1;j<=n;++j)
			dp[0][j] = 0;		
		dp[0][0]=1;
		
		for(int i=1;i<=t;++i)
		{
			dp[i][0]=1;
			for(int j=1;j<=n;++j)
				dp[i][j] = dp[i-1][j]*np + dp[i-1][j-1]*p;
		}
		
		for(int j=1;j<=n;++j)
			sum += dp[t][j] ;
		
		
		printf("%lf\n",sum);
		
	};
	return 0;
};
/*
1 0.50 1
1 0.50 4
4 0.20 2
*/

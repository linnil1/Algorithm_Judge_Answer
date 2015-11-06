#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 4010
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	bool operator < (const xy &b)const
	{
		return x<b.x;
	}
};

int dp[M][M];
xy arm[M],she[M];

#define dist(a,b) std::abs(arm[a].x-she[b].x)

int n,m;
void godp()
{
	
	/*for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			dp[i][j] = INT_MAX;*/
			
	int vis[m];
	memset(vis,0,sizeof(vis));
	
	dp[0][0] = dist(0,0);	
	
	for(int i=1;i<n;++i)
	{
		int fa = vis[i-1];
		
		dp[i][fa] = dp[i-1][fa] + dist(i,fa) ;
		vis[i] = fa;
		
		++fa;
		if(fa<m && dp[i-1][fa] + dist(i,fa) < dp[i][fa] )
		{
			dp[i][fa] = dp[i-1][fa] + dist(i,fa) ;
			vis[i] = fa;
		}
	}
	
	printf("%d\n",dp[n-1][m-1]);
		
	
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	while(~scanf("%d",&n))
	#endif	
	{		
		for(int i=0;i<n;++i)
		{
			scanf("%d",&arm[i].x);
			arm[i].y = i;
		}
		scanf("%d",&m);		
		for(int i=0;i<m;++i)
		{
			scanf("%d",&she[i].x);
			she[i].y = i;
		}
		std::sort(arm,arm+n);
		std::sort(she,she+m);
		
		godp();
			
		
	};
	return 0;
};
/*
*/

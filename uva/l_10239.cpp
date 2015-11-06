#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 1010
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

double dp[M][M];
struct book
{
	double h,w;
}b[M];

	
int n;
double k;

double todp()
{
	double sum[M];
	sum[0]=0;
	for(int i=0;i<n;++i)
		sum[i+1] = sum[i]+b[i].w;
		
	double dp[M];
	dp[0]=0;
	for(int i=0;i<n;++i)
	{
		double max = 0;
		dp[i+1] = INT_MAX;
		for(int j=i;j>=0 && sum[i+1]-sum[j]-k<=1e-9 ; --j)
		{
			max = std::max(max , b[j].h);
			dp[i+1] = std::min( dp[i+1] , dp[j] + max);
		}		
	}
	return dp[n];
	
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
	while(~scanf("%d%lf",&n,&k)&&n)
	#endif	
	{
		
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&b[i].h,&b[i].w);
				
		printf("%.4lf\n",todp());
		
	};
	return 0;
};
/*
*/

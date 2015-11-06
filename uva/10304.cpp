#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 500
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

int arr[M],dp[M][M],sum[M];

#define findsum(a,b) (sum[b+1]-sum[a])
int godp(int a,int b)
{
	if(a>b || a==b)
		return 0;
	
	if(dp[a][b]!=INT_MAX)
		return dp[a][b];
	
	for(int i=a;i<=b;++i)
		dp[a][b] = std::min ( dp[a][b] ,
			 godp(a,i-1) + godp(i+1,b) + findsum(a,b) - findsum(i,i) );
	return dp[a][b];
	
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
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
			
		for(int i=sum[0]=0;i<n;++i)
			sum[i+1] = sum[i] + arr[i];	
		
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dp[i][j] = INT_MAX;	
			
		printf("%d\n",godp(0,n-1));
			
	};
	return 0;
};
/*
*/

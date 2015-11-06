#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100
#define INF 0x7fffffff
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

int dp[M][M],arr[M];;

int godp(int a,int b,int l,int r)
{
	if( a > b )
		return 0;
	else if(dp[a][b]!=INF)
		return dp[a][b];
	
	for(int i=a;i<=b;++i)
		dp[a][b] = std::min( dp[a][b] , 
			godp(a,i-1,l,arr[i]) +  godp(i+1,b,arr[i],r) + r-l );
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
	int k,n;
	while(~scanf("%d",&k)&&k)
	#endif	
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dp[i][j]=INF;
		
		printf("The minimum cutting is %d.\n",godp(0,n-1,0,k));
			
		
	};
	return 0;
};
/*
*/

#include<cstdio>
#include<algorithm>
#define N 110
#define M 10100

int lim[N][M],
	val[N][M],
	dp[2][M];

int n,m,k;
void todp()
{
	int now=1;
	for(int q=0;q<n;++q)
	{
		memset(dp[now],0,sizeof(int)*(m+1));
		int s=0,e=0,sum=0,all=0;
		for(;sum + lim[q][e] <= k && e < m ; ++e)
			sum += lim[q][e] ,
			all += val[q][e] ;
			
		if( dp[!now][e] + all - val[q][e] > dp[now][e])
			dp[now][e] = dp[!now][e] + all - val[q][e-1] ;
		if( dp[!now][s] + all - val[q][s] > dp[now][s])
			dp[now][s] = dp[!now][s] + all - val[q][e-1] ;
		
		
	};
}

int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		++n;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&val[i][j]);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&lim[i][j]);
				
		for(int j=0;j<=m;++j)
			dp[0][j]=0;
			
		todp();
				
		
				
				
	};
	return 0;
};
/*

*/

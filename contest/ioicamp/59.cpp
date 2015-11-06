#include<bits/stdc++.h>
#define M -1
#define lld long long int 

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int n,k,s;
		int dp[1010][1010];
		
		scanf("%d%d%d",&n,&k,&s);
		
		int min = std::min( n , s);
		
		for(int i=0;i<=k;++i)
			for(int j=0;j<=s;++j)
				dp[i][j] = M ;
		
		dp[0][0] = 1 ;
		
		for(int i=1;i<=min;++i)
			for(int a=k;a>=1;--a)
				for(int j=s;j>=i;--j)				
					if( dp[a-1][j-i] != M  )
					{
						if(dp[a][j] == M)
							dp[a][j] = 0;
						dp[a][j] +=  ( dp[a-1][j-i] ) ;
					}
		/*	
		for(int i=0;i<=k;++i,puts(""))
			for(int j=0;j<=s;++j)
				printf("%d ",dp[i][j]);
		*/
		printf("%d\n",dp[k][s] == M ? 0 : dp[k][s]);
		
	}
    return 0;
}

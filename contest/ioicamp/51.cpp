#include<bits/stdc++.h>

#define lld long long int 
struct men
{
	int x,y;
};

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int dp[2100],n;
		
		
		scanf("%d",&n);
		
		men m[n];
		int sumx=0,sumy=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&m[i].x,&m[i].y);
			m[i].x/=1000;
			sumx+=m[i].x;
			sumy+=m[i].y;
		};
#define M 2147483647
		for(int i=0;i<=sumx;++i)
			dp[i] = M ;
		
		
		dp[0] = sumy;
		//dp[sumx] = 0 ;
		
		//puts("zxc");
		for(int i=0;i<n;++i)
			for(int j=sumx;j>=m[i].x;--j)
				if( dp[j-m[i].x]!=M && dp[j] > dp[j-m[i].x] - m[i].y )
					dp[j] = dp[j-m[i].x] - m[i].y ;
					
		/*for(int i=0;i<=sumx;++i)
			printf("%d ",dp[i]);		
		puts("");	*/
					
		for(int i=0 ; i<=sumx ;++i)
			if(dp[i]!=M && i*1000 >= dp[i] )
			{
				printf("%d\n",i*1000);
				break;
			};
				
		
		
	}
    return 0;
}

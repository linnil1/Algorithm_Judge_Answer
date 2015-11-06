#include<bits/stdc++.h>
#define M 1100
int dp[M][M];
int ch[M];

inline int todp(int a,int b)
{
	if(dp[a][b])
		return dp[a][b] ;
	else if(a == b)
		return dp[a][b] = 1;
	else if(a > b )
		return dp[a][b] = 0;
		
	return dp[a][b] = std::max ( std::max ( todp(a+1,b) , todp(a,b-1) ) ,  todp(a+1,b-1) + 2*(ch[a]==ch[b])  );		
};

#define forr(i,n) for(int i=0;i<n;++i)


int ans[M],anss;
int find(int now,int a,int b,int lay)
{
	if( a>b )
		return 0;
	
	for(int i=a;i<=b && dp[i][b] == now && (lay>=anss || ch[i] <= ans[lay] ) ;++i)
		for(int j=b; j>=i  && dp[i][j] == now;--j)
			if(i==j)
			{
				//printf("%d %d %d\n",ch[i],now,lay);
				if(lay>=anss || ch[i] < ans[lay] )
				{
					ans[lay] = ch[i];
					anss = lay + 1 ;				
				}
			}
			else if( ch[i] == ch[j] && dp[i+1][j-1] + 2 == now)
			{
				//printf("%d %d %d %d\n",i,j,now,lay);
				if(lay>=anss || ch[i] <= ans[lay] )
				{
					ans[lay] = ch[i];
					anss = lay + 1 ;										
					find(now-2,i+1,j-1,lay+1);
					break;
				}
			}
	
	
};

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		
		for(int i=0;i<n;++i)
			scanf("%d",ch+i);
			
		forr(i,n)
			forr(j,n)
				dp[i][j] = 0;
		
		int max = todp(0,n-1);
						
		anss = 0;
		
		find(max,0,n-1,0);
		
		forr(i,anss)
			printf("%d ",ans[i]);
		if(max%2)
			--anss;
		for(int i=anss-1;i>=0;--i)
			printf("%d ",ans[i]);
		puts("");
		
		
		//printf("%d\n",);
	};
	return 0;
};
/*
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 2010

int val[M][M];
int n,man,pack;

struct ka
{
	int next,cost,val;
}c[M];

void togofrom()
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			val[i][j] = 0;
	for(int i=0;i<n;++i)
	{
		int now = c[i].cost ,value = 0;
		for(int j=i;j<n;++j)
		{
			if(now + c[j].cost <= pack)
				val[i][j] = value + c[j].val;
			else if(j)
				val[i][j] = val [i][j-1];
				
			if(now + c[j].next <= pack)
			{
					now += c[j].next ;	
					value += c[j].val ;
			}
			else
				now = pack+1;
		};
	};
	/*for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<n;++j)
			printf("%d ",val[i][j]);*/
};

int todp()
{
	int dp[man+1][n],
		from[man+1][n];
	memset(dp,0,sizeof(dp));
	for(int j=0 ; j<n ; ++j)
		for(int i=0 ; i<=man ; ++i)
			from[i][j]=-1;
	
	//for(int i=0;i<=man;++i)
	dp[1][0] = val[0][0];
	from[1][0] = 0;
		
	
	
	for(int j=1 ; j<n ; ++j)
		for(int i=1 ; i<=man ; ++i)
		{
			if(from[i][j-1] == -1 || 
				dp[i-1][j-1] + val[j][j]  >
				dp[i][j-1]  - val[ from[i][j-1] ][ j-1 ] + val[ from[i][j-1] ][ j ])
			{
				dp[i][j] = dp[i-1][j-1] + val[j][j];
				from[i][j] = j;
			}
			else /*if(dp[i-1][j-1] + val[j][j]  <
				dp[i][j-1]  - val[ from[i][j-1] ][ j-1 ] + val[ from[i][j-1] ][ j ])*/
			{
				dp[i][j] = dp[i][j-1]  - val[ from[i][j-1] ][ j-1 ] + val[ from[i][j-1] ][ j ] ;
				from[i][j] = from[i][j-1];
			}
			
		};
		
	//printf("%d\n",dp[man][n-1]);
	/*for(int i=0 ; i<=man ; ++i,puts(""))
		for(int j=0 ; j<n ; ++j)		
			printf("%d ",dp[i][j]);*/
	int max=0;
	for(int i=0;i<=man;++i)
		max = std::max( max , dp[i][n-1]);
	return max;
			
	
};
/*
3
3
10 2 3
10 4 2
10 5 5
11 1
3
10 2 3
10 4 2
10 5 5
11 2
3
10 2 3
10 4 2
10 5 5
11 3

3
4
10 1 2
10 100 2
10 100 2
10 100 100
20 1
1
100 10 10
20 1
1
100 10 10
10 1

*/
int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d%d%d",&c[i].val,&c[i].cost,&c[i].next);
			
		scanf("%d%d",&pack,&man);		
		
		togofrom();
		printf("%d\n",todp());
		
		
	};
	return 0;
};

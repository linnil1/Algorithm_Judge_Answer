#include<bits/stdc++.h>

int dp[1100][1100];
int ch[1100];

inline int todp(int a,int b)
{
	if(dp[a][b])
		return dp[a][b] ;
	else if(a == b-1)
		return dp[a][b] = 1;
	else if(a > b - 1 )
		return dp[a][b] = 0;
		
	return dp[a][b] = std::max ( std::max ( todp(a+1,b) , todp(a,b-1) ) ,  todp(a+1,b-1) + 2*(ch[a]==ch[b-1])  );		
};

void find(int now,int a,int b)
{
	std::stack<int > s;
	
	while(a <= b-1)
	{
		if( a == b-1)
		{
			s.push(ch[a]);
			++a;
		}
		else if(ch[a] == ch[b-1] && dp[a+1][b-1] + 2 == now)
		{
			now-=2;		
			printf("%d ",ch[a]);	
			s.push(ch[a]);	
			++a;
			--b;
		}
		else if(dp[a+1][b]== now )
			++a;
		else if(dp[a][b-1] == now )
			--b;
	};
	
	while(s.size())
	{
		printf("%d ",s.top());
		s.pop();
	}
	puts("");
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
			
		std::fill(&dp[0][0],&dp[n][n],0);
		
		int max = todp(0,n);
		
		find(max,0,n);
			
		//printf("%d\n",);
	};
	return 0;
};
/*
*/

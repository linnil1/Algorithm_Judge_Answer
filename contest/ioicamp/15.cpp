#include<bits/stdc++.h>
#define lld long long int
#define yesT 
#define M 50100
#define no -1
lld dp[M];
int subdp[M];


void pack(int v,int p,int s)
{
	if(p&&s)
		for(v-=p;v>=0;--v)
			if(dp[v]!=no && dp[v]+s > dp[v+p])
			{
				dp[v+p] = dp[v] + s;
				subdp[v+p] = 1;
			};
}

void special(int v,int p,int s)
{
	for(v-=p;v>=0;--v)
		if(subdp[v]==1 &&dp[v]+s > dp[v+p])
		{			
			dp[v+p] = dp[v] + s;
			subdp[v+p]=1;
		}
}
lld tomax(int v)
{
	lld max=no;
	for(int i=0;i<=v;++i)
		if(dp[i] > max)
			max = dp[i];
	return max;
}
int main()
{
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n,v;
		scanf("%d%d",&n,&v);
		
		for(int i=0;i<=v;++i)
			dp[i]=no;
		dp[0] = 0;
		
		while(n--)
		{
			for(int i=0;i<=v;++i)
				subdp[i]=no;
			//limitpack
			int p,s,a;
			scanf("%d%d%d",&p,&s,&a);
			
			if(a!=2)
			{
				int i=2;
				--a;
				while(i<=a)
				{
					a-=i;
					pack(v,p*i,s*i);	
					i<<=1;			
				}
				if(a!=1)
					pack(v,p*a,s*a);
				else
					special(v,p,s);
				special(v,p,s);
			}
			else
				pack(v,p*2,s*2);
		}
		
		printf("%lld\n",tomax(v));
	};
	return 0;
};
/*
*/

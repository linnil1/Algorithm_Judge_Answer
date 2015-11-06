#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

int need[10]={6,2,5,5,4,5,6,3,7,6};
pii dp[M];

void cut(int &n,int &k)
{
	while(k%10 == 0)
	{
		k/=10;
		n-=need[0];
	}
	
}

int todig(int a)
{
	int sum=1;
	while(a)
	{
		sum*=10;
		a/=10;
	}
	return sum;
}

inline int count(int a)
{
	int sum=0;
	while(a)
	{
		sum += need[a%10];
		a/=10;
	}
	return sum;
}

void permu(int k)
{
	int t=todig(k)*10;
	for(int i=1;i<t;++i)
		dp[i]= mp( i*k* , count(i*k) );
}

void find(int n,int k)
{
	int t=todig(k)*10;
	std::sort(dp+1,dp+t);
	
	int now=0;
	dp[now++] = dp[1] ;
	for(int i=2;i<t;++i)
		if( dp[i].second != dp[now-1].second)
			dp[now++] = dp[i];
		else if(dp[i] > dp[now-1])
			dp[now-1] = dp[i];
			
	for(int i=0;i<now;++i)
		printf("%d %d\n",dp[i].first*k,dp[i].second);
		
	int time = n/dp[0].second;
	if(time==0)
	{
		puts("-1");
		return ;
	}
	n%=dp[0].second;
	
	for(int i=now-1;i>0 && n;--i)
		while(n >= dp[i].second)
		{
			printf("%d",dp[i].first*k);
			n-=dp[i].second;
			time--;
		}
		
	while(time--)
		printf("%d",dp[0].first*k);
	puts("");
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
	int n;
	while(~scanf("%d",&n)&&n)
	#endif	
	{
		int k;
		scanf("%d",&k);
		
		cut(n,k);
		if(n<=0)
		{
			puts("-1");
			continue;
		}
		permu(k);
		find(n,k);
				
	};
	return 0;
};
/*
*/

#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 1001
#define MOD 1000000007
#define mp std::make_pair
#define pii std::pair<int,int>
#define pb push_back
#define qi std::queue<int>
#define vi std::vector<int>


struct prime
{
	int p[M],ps;
	char c[M];
	
	prime()
	{
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<M;++i)
		{
			if(c[i])
				p[ps++]=i;
			for(int j=0;j<ps && i*p[j]<M;++j)
			{
				c[ i*p[j] ]=0;
				if( i % p[j] == 0)
					break;
			}
		}
	}
	int i;
	int isprime(int a,int b=0)
	{
		if(b) i=0;
		int t = (int)sqrt(a);
		for(i; i<ps && p[i]<=t ;++i)
			if(a % p[i] == 0)
				return p[i];
		return a;
	}
	
}p;

vi vp[M*M],permu[M*M];


void dfs(int &a,int mult,int now,int i,vi &v)
{
	if(!now)
	{
		permu[a].pb(mult);
		return ;
	}
	for( ;i<v.size();++i)
		dfs(a, mult*v[i] , now-1 , i+1, v);
		
}

void find(int a)
{
	vp[a].clear();
	permu[a].clear();
	int now = a;
	p.isprime(now,1);	
	
	while(now!=1)
	{
		int t=p.isprime(now);
		vp[a].pb(t);
		while(now%t == 0)
			now/=t;
	}
	
	
	for(int i=0;i<=vp[a].size();++i)
		dfs(a,i%2 ? -1:1 ,i ,0,vp[a]);
	
	/*printf("%d : ",a);
	for(int i:permu[a])
		printf("%d ",i);
	puts("");*/
}

ll eulur(int a,int b)
{
	ll sum=0;
	for(int i:permu[b])
		sum+= a/i ;
	return sum;
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	for(int i=1;i<=1000000;++i)
		find(i);
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b)
			std::swap(a,b);
			
		ll sum=0;
		for(int i=1;i<=b;++i)	
			sum+=eulur(a,i);
			
		printf("%lld\n",sum);
		
		
	};
	return 0;
};
/*
*/

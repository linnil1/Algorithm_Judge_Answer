#include<bits/stdc++.h>

#define ll long long int
#define yesT

#define M 1000000

struct prim
{
	int pr[M],ps;
	char c[M+1];
	void init()
	{
		//puts("zxc");
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<=M;++i)
		{
			if(c[i])pr[ps++]=i;
			for(int j=0;j<ps && pr[j]*i<=M ; ++j)
			{
				c[ pr[j]*i ] = 0 ;
				if(i%pr[j]==0)
					break;
			};
			
		}
	}
	
	int i;
	ll isprim(ll &a)
	{		
		ll n = (ll)sqrt(a);
		for( ;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	
};


prim p;
#define MOD 1000000007
std::unordered_map<ll,int > um; 
void predo(ll &a)
{
	p.i=0;
	while(a!=1)
	{
		ll k = p.isprim(a);
		if(k > 1000000000000ll )
			return ;		
		while(a%k==0)
			a/=k,
			++um[k];					
	}
}

ll gcd(ll a,ll b){ return b==0 ? a : gcd(b,a%b);}
void gogcd(ll *arr,int n)
{
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
			ll k= gcd(arr[i],arr[j]);
			if(k==1)
				continue;
			
			for(int q=0;q<n;++q)
				while(arr[q]%k==0)
				{
					arr[q]/=k;
					++um[k];
				}
		}
}

void gosqrt(ll *arr,int n)
{
	for(int i=0;i<n;++i)
		if(arr[i]!=1)
		{
			ll k =(ll)sqrt(arr[i]);
			if( k*k == arr[i] )
			{			
				um[k]+=2;			
				arr[i]=1;
			}
		}
}

void pick(ll *arr,int n)
{
	for(int i=0;i<n;++i)
		if(arr[i]!=1)
			++um[arr[i]];
}


ll pow(ll a,int b)
{
	ll sum=1;
	a%=MOD;
	while(b)
	{
		if(b&1)
			sum = sum * a %MOD;
		b>>=1;
		
		a= a*a%MOD;
	}
	return sum;
}

ll count()
{
	ll sum=1;
	
	for(auto a:um)
	{
		ll b = a.first%MOD ;
		sum = sum * pow(b , a.second ) % MOD;
		
		int time = (3 - a.second%3 )%3;
		while(time--)
			sum = sum * b % MOD ;
	};
	return sum ;	
}

int main()
{
	p.init();
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n;
		scanf("%d",&n);
		
		ll arr[n];
		um.clear();
		for(int i=0;i<n;++i)
		{
			scanf("%lld",arr+i);
			predo(arr[i]);
		};
			
		gogcd (arr,n);
		gosqrt(arr,n);
		pick(arr,n);		
				
		printf("%lld\n",count());
		
	};
	return 0;
};
/*
*/

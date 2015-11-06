#include<bits/stdc++.h>
#define ll long long 
#define M 2010
#define MOD 1000000000
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>

using std::cin;using std::cout;using std::string;
using std::sort;using std::endl;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MANN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;
#define pm 550


struct prim
{
	const static int MM=4000;
	int pr[MM],ps;
	char c[MM+1];
	void init()
	{
		//puts("zxc");
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<=MM;++i)
		{
			if(c[i])pr[ps++]=i;
			for(int j=0;j<ps && pr[j]*i<=MM ; ++j)
			{
				c[ pr[j]*i ] = 0 ;
				if(i%pr[j]==0)
					break;
			};			
		}
		//cout << ps << endl ;
	}	
	int findprim(int a)
	{		
		//be careful at 0,1 
		for(int i=0;i<ps;++i)
			if( a % pr[i] == 0)
				return i;
	}	
};
prim p;


void pluss(VI &a,VI& b)
{
	FR(i,a.size())
		a[i]+=b[i];
}
void minuss(VI &a,VI& b)
{
	FR(i,a.size())
		a[i]-=b[i];
}

VI fact[4000];
void makefact()
{
	p.init();	

	fact[0]=fact[1]= VI(pm);
	FOR(i,2,4000)
	{	
		int t = p.findprim(i);
		fact[i] = fact[i/p.pr[t]];
		++fact[i][t];		
	};
	FOR(i,3,4000)
	{
		pluss(fact[i],fact[i-1]);
	}
}
ll ipow(ll e,int t)
{
	ll sum=1;
	while(t)
	{
		if(t&1)
			sum = sum * e %MOD;	
		e = e*e%MOD;
		t>>=1;
	}
	return sum;
}
ll vtoint(VI &v)
{
	ll sum=1;
	FR(i,v.size())
		if(v[i])
			sum = sum*ipow(p.pr[i],v[i])%MOD;
	return sum;
}
ll H_enum(int a,int b)
{
	VI now(pm);
	pluss(now,fact[a+b-1]);
	minuss(now,fact[a-1]);
	minuss(now,fact[b]);
	return vtoint(now);
}

ll one[M],sum[M];

void toone(int m,int n)
{
	for(int i=0;i<=m;++i)
		one[i] = H_enum(m,i);
}

void toall(int m,int n)
{
	sum[0] = one[0];
	for(int i=1;i<=m;++i)
		sum[i]=one[i];
	
	for(int i=2;i<=n;++i)
	{
		ll s=one[0];
		for(int j=1;j<=m;++j)
		{
			s = (s+sum[j])%MOD;
			sum[j] = (one[j]*s) %MOD;
		}
	}
}

ll gosum(int m)
{
	ll s = 0 ;
	for(int j=0;j<=m;++j)
		s = (s+sum[j])%MOD;
	return s ;
	
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	makefact();
	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	int n , m;
	while(cin >> n >> m)
	{
		
		toone(m,n);
		toall(m,n);
		cout << gosum(m) << endl;
	};
}
	return 0;
};
/*

1hr late




*/

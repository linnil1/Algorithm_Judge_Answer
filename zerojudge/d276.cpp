#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define FORE(i,a,n) for(int i=a;i<=n;++i)
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
#define MINN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

struct prim
{
	const static int MM=100000;
	int pr[MM/10],ps;
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
	}
	
	ll isprim(ll &a)
	{		
		//be careful at 0,1 
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	ll thepr(ll &a)
	{
		ll k = isprim(a);
		while(1)
		{
			while(a%k==0)
				a/=k;
			if(a==1)
				return k;			
			k = isprim(a);
		}	
	}
	
};

prim p;

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	ll  n;
	p.init();
	while(cin >> n)
	{
		
		if(n==0)
			puts("Answer Is Too Big!");
		else if(n==1)
			puts("Nothing");
		else if(n<0)
			puts("別鬧了  這明明很簡單");
		else
			cout << p.thepr(n) << endl ;
			
	};
}
	return 0;
};
/*






*/

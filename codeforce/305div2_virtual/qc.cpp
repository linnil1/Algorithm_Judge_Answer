#include<bits/stdc++.h>
#define ll long long 
#define M 1000010
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

int mod,day[M];

int start(ll a,ll e,ll x,ll y)
{
	FR(i,mod)
		day[i]=-1;
			
	int now=1;
	day[a]=0;
	a= (x*a+y)%mod;
	while(a!=e)
	{		
		if(day[a]!=-1)
			return -1;
		day[a]=now++;
		a= (x*a+y)%mod;
	}
	if(a==e)
		return now;	
}

int end(ll a,ll e,ll x,ll y)
{
	FR(i,mod)
		day[i]=-1;
	a=e;
	int now=1;
	day[a]=0;
	a= (x*a+y)%mod;
	while(a!=e)
	{		
		if(day[a]!=-1)
			return -1;
		day[a]=now++;
		a= (x*a+y)%mod;
	}
	if(a==e)
		return now;	
}


ll ans(ll sa,ll sb,ll ra,ll rb)
{
	if(sa==-1 || sb==-1 )
		return -1;
	if(sa==sb)
		return sa;
	if(ra==-1  && sa>sb && (sa-sb)%rb==0)
		return sa;
	if(rb==-1  && sb>sa && (sb-sa)%ra==0)
		return sb;
	if(ra==-1 || rb==-1)
		return -1;
		
	FR(i,mod+2)
		if( (sa+ra*i-sb)>=0 && (sa+ra*i-sb) %rb ==0 )
			return sa+ra*i;
	return -1;
		
		
	
	
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	while(cin >> mod)
	{
		ll a[2],e[2],x[2],y[2];
		cin >> a[0] >> e[0] >> x[0] >> y[0];
		cin >> a[1] >> e[1] >> x[1] >> y[1];
		int daya = start(a[0],e[0],x[0],y[0]),
			dayb = start(a[1],e[1],x[1],y[1]);
		
		int ra = end(a[0],e[0],x[0],y[0]),
			rb = end(a[1],e[1],x[1],y[1]);
		
		cout << ans(daya,dayb,ra,rb) << endl;
		
	};
}
	return 0;
};
/*
nearly good
but finally the last step which less than mod steps
can't find out on time;




*/

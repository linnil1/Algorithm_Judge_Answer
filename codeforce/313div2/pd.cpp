#include<bits/stdc++.h>
#define ll long long 
#define M 200100
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_tuple
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::tuple<int,int,int>
//using namespace std;

int ok=0;
std::map< MP , bool > s;
int dfs(int a,char *c,int b,char *d,int n)
{
	auto k = mp(a,b,n) ; 
	if( s.count( k ) )
		return  s[k];
	int now=1;
	for(int i=0;i<n&&now;++i)
		if(c[a+i]!=d[b+i])
			now=0;
	if(now)
		return s[ k] = 1 ;
	
	if(n%2==1)
		return s[ k] = 0 ;
		
	if( dfs(a+n/2,c,b,d,n/2) &&  dfs(a,c,b+n/2,d,n/2))
		return s[k] = 1 ;
	if( dfs(a,c,b,d,n/2) &&  dfs(a+n/2,c,b+n/2,d,n/2))
		return s[k] = 1 ;
	return s[k ] = 0 ;
		
		
}

char c[M],d[M];

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	while(times-- && ~scanf("%s%s",c,d)){	
		int n = strlen(c);
		ok=0;
		s = std::map< MP , bool >();
		printf("%s\n",dfs(0,c,0,d,n)?"YES":"NO" );
		
	};

	return 0;
};
/*






*/

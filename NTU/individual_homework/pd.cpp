#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1000000007
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
#define MP std::pair<int,int>
//using namespace std;
#define bs(c) (c>='a' ? c-'a'+26 : c-'A')
ll dp[5010][1010];
VMP v[52];
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m,p;string s;
	while(cin >> n >> m >> p >> s){
		FR(i,52)
			v[i] = VMP();
		while(m--){
			int x,y;char c[10];
			cin >> x >> y >> c; 
			v[ bs(c[0]) ].pb( mp(x,y) );
		}
		int sz = s.size();
		FR(i,sz)
			FR(j,n)			
				dp[i][j]=0;
		
		for(MP &i : v[ bs(s[0]) ])
			++dp[0][ i.sd ];
		
		FOR(i,1,sz)
			for(MP &j : v[bs(s[i])])
				dp[i][j.sd] = (dp[i][j.sd]+ dp[i-1][j.ft] )%p;
		ll sum=0;
		FR(i,n)
			sum = (sum+dp[sz-1][i])%p;
			
		cout << sum%p << endl;
	};
}
	return 0;
};
/*






*/

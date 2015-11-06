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
const int MM=1000100;
int s[MM],g[MM];
struct disjointset
{
	int n,out,link[10010],group;
	void init(int _n)
	{
		group = n = _n ;
		for(int i=1;i<=n;++i)
			s[i] = i ,
			g[i] = 1 , 
			link[i] = i ;
		out = n+1;
	};
	
	inline int find(int a)
	{
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b)
	{
		a=link[a];b=link[b];
		if(find(a)!=find(b))
		{
			g[find(b)] += g[find(a)];
			g[find(a)] = 0;
			s[find(a)] = find(b);			
			--group;
			return 1;
		}
		else
			return 0;
	}	
	int iso(int a){
		int now = link[a];		
		if( g[find(now)] ==1)
			return 0;
		--g[find(now)];
		link[a] = out ;
		g[out] = 1;
		s[out] = out;
		++group;
		++out;
		return 1;
	}
	
}disj;


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(cin >> n >> m){
		disj.init(n);
		while(m--){
			int type,x,y;cin >>type >> x;
			if(type==1){
				cin >> y ;			
				disj.unin(x,y);
			}
			else
				disj.iso(x);
		}
		cout << disj.group << endl;
	};
}
	return 0;
};
/*






*/

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
struct xy
{
	int f,t,v,c;
};
struct dijkstra
{
	typedef std::pair<int,int> pii ;
	static const int MM = 100000;
	std::vector< pii > v[MM];	
	VI cost[MM];
	int ver[MM],use[MM];
	int n,m;
	void init(int _n)
	{
		n=_n;
		for(int i=1;i<=n;++i)
			v[i] = std::vector< pii >(),
			cost[i] = VI();
	}
	void add(int &x,int& y,int &val,int& c)
	{
		v[x].pb ( mp(y,val) );
		
		v[y].pb ( mp(x,val) );
		cost[x].pb( c);
		cost[y].pb( c);
	}
	void go(int s=0)
	{
		for(int i=1;i<=n;++i)
			ver[i]=INT_MAX,use[i]=0;
		ver[s]=0;
		std::priority_queue< pii ,
		std::vector< pii > ,
		std::greater< pii > > q;
		q.push( mp(0,s) );
		while(q.size())
		{
			int now =q.top().sd;q.pop();
			if(use[now])continue;
			use[now]=1;
			for(auto i:v[now])
				if(ver[i.ft] > ver[now]+i.sd)
				{
					ver[i.ft] = ver[now]+i.sd ;
					q.push( mp(ver[i.ft],i.ft) );
				}
		}		
	}
	ll gsum(){
		ll sum=0;
		/*FRE(i,n)
			cout << ver[i] << " ";
		cout << endl;*/
		for(int i=2;i<=n;++i){
			ll c=INT_MAX;
			FR(j,v[i].size())			
				if(ver[i]== ver[v[i][j].ft]+v[i][j].sd &&  c>cost[i][j]){
					c = cost[i][j];
					//cout << i << ' ' << j << endl;
				}
			sum +=c ;
		}
		return sum;			
	}	
}dij;


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(cin >> n >> m && n ){
		dij.init(n);
		FR(i,m){
			int a,b,c,d;
			cin >> a >> b >> c >> d;
			dij.add(a,b,c,d);
		}
		dij.go(1);
		cout << dij.gsum() << endl;
		
	};
}
	return 0;
};
/*






*/

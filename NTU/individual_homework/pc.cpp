#include<bits/stdc++.h>
#define ll long long 
#define M 100100
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

struct scc{
	static const int MM = 100100;
	int n;
	VI v[2][MM];
	void init(int& _n){
		n = _n;
		for(int i=0;i<=n;++i)
			v[0][i]=v[1][i]=VI();
	}
	void add(int& x,int& y){
		v[0][x].pb(y);
		v[1][y].pb(x);
	}
	
	int topo[MM],ton,vis[MM];
	
	typedef std::pair<int,int> pii ;
	void dfs1(int now){		
		std::stack< pii > s;
		s.push( mp(now,-1) );
		vis[now]=-1;
		while(s.size()){
			pii &now = s.top();			
			for(++now.sd ; now.sd < v[1][now.ft].size() ;++now.sd)
				if( !vis[ v[1][now.ft][now.sd]]){
					vis[ v[1][now.ft][now.sd]] = -1 ;
					s.push( mp( v[1][now.ft][now.sd], -1) );
					break;
				}
			if( now.sd == v[1][now.ft].size() ){
				topo[ton++]= now.ft ;
				s.pop();				
			}	
		}
	}
	/*
	void dfs1(int now){
		if(vis[now]==-1)
			return ;
		vis[now]=-1;
		for(int &j:v[1][now])
			dfs1(j);
		topo[ton++]=now;
	}*/
	/*void dfs(int now){
		if(vis[now]!=-1)
			return ;
		vis[now]= ton;
		for(int &j:v[0][now])
			dfs(j);
	}*/
	void dfs(int now){
		std::queue< int > s;
		s.push( now );vis[now]=ton ; 
		while(s.size()){
			//puts("zxc");
			int now = s.front();s.pop();			
			for(int &j : v[0][now])
				if(vis[j]==-1){				
					s.push(j);
					vis[j]=ton;
				}
		}
	}
	
	void goscc(){
		for(int i=0;i<=n;++i)
			vis[i]=0;
		ton=0;
		for(int i=0;i<n;++i)//!!
			if(!vis[i])
				dfs1(i);
		ton=0;
		for(int i=n-1;i>=0;--i)//!!
			if(vis[topo[i]]==-1){			
				dfs(topo[i]);			
				++ton;
			}
	}
	
	
}sa;

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	int n,m;
	while(times-- && ~scanf("%d%d",&n,&m) && n){	
		sa.init(n);
		while(m--){
			int x,y;scanf("%d%d",&x,&y);
			sa.add(x,y);
		}
		sa.goscc();
		
		printf("%d\n",sa.ton);
		
		
	};

	return 0;
};
/*






*/

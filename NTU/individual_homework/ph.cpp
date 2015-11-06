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

struct E
{
	int go,val;
	E(){};
	E(int _go,int _val):go(_go),val(_val){};
};

struct flow
{
	static const int VM = 500000,VN=10000;
	int n,nuse=0;
	E e[VM];
	VI v[VN];
	void init(int _n)
	{
		n = _n ; nuse=0;
		for(int i=0;i<n;++i)
			v[i] = VI();
	}
	void add(int a,int b,int val)
	{
		v[a].pb(nuse);e[nuse]=E(b,val);++nuse;
		v[b].pb(nuse);e[nuse]=E(a,  0);++nuse;
	}
	
	int dis[VN];
	int bfs()
	{		
		for(int i=1;i<n;++i)
			dis[i]=INT_MAX;
		dis[0]=0;
		std::queue<int> q;
		q.push(0);
		while(q.size() )
		{
			int now = q.front() ; q.pop();
			for(int i=0;i<v[now].size();++i)
			{
				E &ee = e[ v[now][i] ] ;
				if(ee.val &&   dis[now]+1 < dis[ee.go] )
				{
					dis[ee.go] = dis[now]+1;
					q.push(ee.go);
				}
				
			}
			/*for(int i=0;i<n;++i)
				printf("%d ",dis[i]);
			puts("");*/
			
		}
		return dis[n-1] !=	INT_MAX;
	};
	
	int ptr[VN];
	int go(int to,int val)
	{
		if(to == n-1)
			return val;
		for(int &i=ptr[to];i<v[to].size();++i)
		{
			E &ee =e[ v[to][i] ];
			if(ee.val && dis[to]+1==dis[ee.go] )
			{
				int plu = go(ee.go , std::min(val,ee.val) );
				if(plu)
				{
					ee.val-=plu;
					e[ v[to][i]^1 ].val +=plu;
					return plu;
				}
			}
			
		}
		return 0;
	}
	
	int maxflow()
	{
		int sum=0,tmp;
		while(bfs())
		{
			for(int i=0;i<n;++i)
				ptr[i]=0;
			while( (tmp=go(0,INT_MAX)) )
				sum+=tmp;
		};
		return sum;
	}
		
}f;

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		f.init(2*n+2);
		FRE(i,n)
			f.add(0,i,1),
			f.add(n+i,2*n+1,1);
			//,f.add(n+i,i,INT_MAX);
		
		ll arr[n];
		FR(i,n){
			cin >> arr[i];
			arr[i]*=arr[i];
		}
		FR(i,n)
			FOR(j,i+1,n)
				if(std::__gcd(arr[i],arr[j])==1){
					ll k = (ll)sqrt(arr[i]+arr[j]);
					if(k*k==arr[i]+arr[j]){
						f.add(i+1,n+j+1,1);
						f.add(j+1,n+i+1,1);
					}
				}
		cout << f.maxflow()/2 << endl;
		
	};
}
	return 0;
};
/*

bipartite matching
= maxflow all edge with max one flow



*/

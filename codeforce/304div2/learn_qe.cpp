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
#define MANN(a,b,c) MIN(MIN(a,b),c)


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
	static const int VM = 10000,VN=10000;
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

void pr(int n,int *arr)
{
	int con[n][n];
	FR(i,n)
		FR(j,n)
			con[i][j]=0;
			
	for(int i=0;i<=n;++i)
		for(int &j:f.v[i+n+1])
			if(j&1 && f.e[j].go<=n)
			{
				con[f.e[j].go-1][i] = f.e[j].val;
				//con[i][i-n] -= f.e[j].val;
			}
	FR(i,n)
	{	
		FR(j,n)
			PR(con[i][j]);
	}
		
	
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(cin >> n >> m)
	{
		f.init(2*n+2);
		int sum=0,ts=0,arr[n];
		FR(i,n)
		{
			cin >> arr[i];
			f.add(0,i+1,arr[i]);
			sum+=arr[i];
		};
		FRE(i,n)
		{
			int a;
			cin >> a;
			ts+=a;
			f.add(n+i,2*n+1,a);
			f.add(i,n+i,INT_MAX);
		}
		while(m--)
		{
			int a,b;
			cin >> a >> b;
			f.add(a,b+n,INT_MAX);
			f.add(b,a+n,INT_MAX);
		}
		
		if(ts!=sum)
			cout << "NO\n";
		else
		{
			//cout <<f.maxflow()<<" "<< sum << endl;
			
			if(f.maxflow()!=sum)
				cout << "NO\n";	
			else
				cout << "YES\n",pr(n,arr);		
		}
	};
}
	return 0;
};
/*






*/

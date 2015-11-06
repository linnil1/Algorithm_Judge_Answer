#include<bits/stdc++.h>
#define ll long long 
#define M 200010
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

char ans[M];
VMP x[M],y[M];
char usex[M],usey[M];

struct xy
{
	int x,y,ch;
};

void go(int i)
{
	std::queue< xy > q;
	q.push( xy{i,0,0} );
	while(q.size())
	{
		xy now = q.front();q.pop();
		
		if(now.y==0)
		{
			for( MP &p : x[now.x])
				if(usey[ p.ft])
				{
					
					usey[p.ft]=0;
				}
		}
		else
		{
			
		}
		
	}
	
	
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		FR(i,n)
			ans[i]=-1;
		FR(i,M)
			x[i]=y[i]= VMP();
		FR(i,M)
			linex[i] 
		FR(i,n)
		{
			int a,b;
			cin >> a >> b;
			x[a].pb( mp(b,i) );
			y[b].pb( mp(a,i) );
		}
		FR(i,M)
			if(x[i].size() && ans[ x[i][0].sd ]==-1 )
			{
				go(i,0);			
			}
		FR(i,n)
			cout << (ans[i]?'b':'r') ;
		cout << endl;
	};
}
	return 0;
};
/*






*/

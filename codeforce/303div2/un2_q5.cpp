#include<bits/stdc++.h>
#define ll long long 
#define M 400010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FROE(i,n) for(int i=0;i<=n;++i)
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
#define MANN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

struct xy
{
	int fr,go,num;
	ll val;
	void in()
	{
		cin >>fr >>go >>val;
		--fr;--go;
	}
}arr[M];
bool operator <(xy a,xy b)
{
	return a.val<b.val;
}

VI ans;
ll bfs(VMP *v,int n )
{
	QI q ;
	ll ver[n] ;
	FR(i,n)
		ver[i]=LLONG_MAX;
	int u;
	cin >> u;
	--u;	
	q.push(u);
	ver[u]=0;
	
	while(q.size())
	{
		int now = q.front();q.pop();
		for(MP &i:v[now])
			if( ver[now]+arr[i.sd].val < ver[i.ft])
			{
				ver[i.ft] = ver[now]+arr[i.sd].val ;
				q.push(i.ft);
			}
	}
	
	ans = VI();
	ll sum=0;
	FR(j,n)
	{
		if(j==u)continue;
		ll min = LLONG_MAX;
		int now=-1;
		for(MP &i:v[j])
			if( ver[j]-arr[i.sd].val == ver[i.ft] && arr[i.sd].val < min)
			{
				
				min = arr[now = i.sd].val;				
			}
		sum+=min;
		ans.pb(now);
	};
	return sum;
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
		VMP v[n];
		FR(i,m)
		{
			arr[i].in();
			arr[i].num=i;
			v[arr[i].fr].pb ( mp(arr[i].go,i));
			v[arr[i].go].pb ( mp(arr[i].fr,i));
		}							
		cout << bfs(v,n)	 << endl;
		for(int &i:ans)
			PR(i+1);
	};
}
	return 0;
};
/*






*/

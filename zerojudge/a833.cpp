#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=0;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define FORE(i,a,n) for(int i=a;i<=n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ARR(arr,n) int arr[n+2];for(int i=0,s=n;i<s;++i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define QI std::queue<int>
#define VI std::vector<int>
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>

#define MP std::pair<int,int>

using namespace std;

void dfs(int s,int n,VMP * v)
{
	ARR(dis,n)
		dis[i]=INT_MAX;	
	dis[s]=0;
	
	QI q;
	q.push(s);
	while(q.size())
	{
		int now = q.front();
		q.pop();
		for(MP i:v[now])
			if(dis[now]+i.sd < dis[i.ft])
			{
				dis[i.ft] = dis[now]+i.sd;
				q.push(i.ft);
			}		
	}
	cout << dis[n-1] << endl ;
	
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(cin >> n >> m)
	{
		VMP v[n];
		while(m--)
		{
			int s;
			MP i;
			cin >> s >> i.ft >> i.sd;
			--i.ft;
			v[s-1].pb(i);
		}
		
		dfs(0,n,v);
				
	};
}
	return 0;
};
/*
*/

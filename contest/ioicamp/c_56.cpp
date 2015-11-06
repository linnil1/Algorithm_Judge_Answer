#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 50100
#define MOD 1000000007
#define mp std::make_pair
#define pii std::pair<int,int>
#define pb push_back
#define qi std::queue<int>

std::vector< pii > cat[M];
int dis[M],vis[M];

void bfs()
{
	qi q;
	q.push(0);
	vis[0] = 1;
	dis[0] = 0;
	while(q.size())
	{
		int now = q.front();
		q.pop();
		
		if(!vis[now])
			continue;
		vis[now]=0;
		
		for(auto p:cat[now])
		{
			if( dis[p.first] < dis[now]+p.second )
			{
				dis[p.first] = dis[now]+p.second;
				vis[p.first] = 1;
				q.push(p.first);
			}
		}		
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<M;++i)
		{
			cat[i].clear();
			dis[i] = -1 ;
			vis[i] = 0 ;
		}
		for(int i=1;i<M;++i)
		{
			cat[i-1].pb( mp(  i, 0) );
			cat[  i].pb( mp(i-1,-1) );
		}
		for(int i=0;i<n;++i)
		{
			int x,y,m;
			scanf("%d%d%d",&x,&y,&m);
			cat[x].pb( mp(y+1, m) );
		}
		
		bfs();
		
		//for(int i=0;i<n)
		
		printf("%d\n",dis[M-1]);
		
	};
	return 0;
};
/*
*/

#include<bits/stdc++.h>
#define ll long long int
#define M 10000
#define VI std::vector<int>
#define pb push_back
#define MIN std::min
#define MAX std::max

VI v[M];
int vis[M],themax;

int dfs(int now){
	//printf("%d ",now);
	if(vis[now]!=-1)
		return vis[now];
	int dep=0,ma=0,max=0;	
	for(int &i:v[now]){
		int k = dfs(i);
		if(k > ma){
			ma = k ;
			if(ma > max )
				std::swap(max,ma);
		}
	}
	//printf("%d %d %d\n",now,ma,max);
	if(max+ma > themax )
		themax = MAX(themax , max+ma);
	return  vis[now] = max+1 ;
}

int main()
{
	int n;
int times;scanf("%d",&times);while(times--)
{
	(~scanf("%d",&n));{
		for(int i=0;i<n;++i)
			v[i]=VI(),
			vis[i]=-1;
		int fa[n];
		for(int i=0;i<n;++i)
			fa[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].pb(y);
			fa[y]=1;
			//v[y].pb(x);
		}
		themax=0;
		for(int i=0;i<n;++i)
			if(fa[i]==0)
				dfs(i);
		printf("%d\n",themax);
		
	}
}
	return 0;
}


/*
1
7
0 1
0 2
0 3
1 4 
1 5
3 6

*/

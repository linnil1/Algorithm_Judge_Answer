#include<bits/stdc++.h>
#define ll long long int
#define M 1111
#define VI std::vector<int>
#define pb push_back
VI v[M];
int vis[M];

void bfs(){
	std::queue<int> q;
	vis[1]=0;
	q.push(1);
	while(q.size()){
		int now = q.front();q.pop();
		for(int &i:v[now])
			if(vis[now]+1 < vis[i]){
				vis[i] = vis[now]+1;
				q.push(i);
			}				
	}
}


int main()
{
	
	int times;scanf("%d",&times);while(times--)
{
	int n,b,r;
	(~scanf("%d%d%d",&n,&b,&r));{
		for(int i=1;i<=n;++i)
			v[i] = VI();
		
		while(r--){
			int x,y;scanf("%d%d",&x,&y);
			v[x].pb(y);
			v[y].pb(x);
		}
		for(int i=1;i<=n;++i)
			vis[i]=INT_MAX;
		bfs();
		if(vis[n]==INT_MAX || b<vis[n]) 
			puts("Stuck in the woods.");
		else
			printf("%d\n",b-vis[n]);
		
		
	}
}
	return 0;
}
/*
2
5 10 5
1 2
1 3
3 5
3 4
4 5
5 2 4
1 2
1 3
3 4 
4 5
  


*/

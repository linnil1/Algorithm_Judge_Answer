//#include<bits/stdc++.h>
#include<algorithm>
#include<cctype>
#include<queue>
#include<cstring>
#define ll long long 
#define yesT
#define M 16
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

#define ch(i) (i-'a')


int path[M][M],
	cost[M][M];
int vx[4]={-4,4,-1,1};
void init()
{
	for(int i=0;i<M;++i)
		for(int j=0;j<M;++j)
			path[i][j]=0;
			
	
	for(int i=0;i<M;++i)
		for(int k=0;k<4;++k)
		{
			int tx=i+vx[k];
			if(tx>=0 && tx<M  && (k<2 || tx/4 == i/4))
				path[i][tx] = 1;
		}		
			
			
	path[ch('f')][ch('g')] = path[ch('g')][ch('f')] =
	path[ch('k')][ch('o')] = path[ch('o')][ch('k')] = 0;
	
	
			
	for(int i=0;i<M;++i)
	{
		qi q;
		q.push(i);
		
		int *val = cost[i];
		for(int j=0;j<M;++j)
			val[j]=INT_MAX;
		val[i]=0;
		
		while(q.size())
		{
			int now=q.front();q.pop();
			
			for(int j=0;j<M;++j)
				if(path[now][j] && val[now]+1 < val[j] )
				{
					val[j] = val[now]+1;
					q.push(j);
				}			
		}		
	}
	/*for(int i=0;i<M;++i,puts(""))
		for(int j=0;j<M;++j)
			printf("%d",path[i][j]);
	for(int i=0;i<M;++i,puts(""))
		for(int j=0;j<M;++j)
			printf("%d ",cost[i][j]);*/
	
}

int min,vis[M],tot;
void dfs(int *vis,int fa,int now,int all)
{
	if(all >= min)
		return ;
	if(now==tot)
	{
		min =std::min(min,all);
		return ;
	}
	for(int i=0;i<M;++i)
		if(vis[i] )
		{
			vis[i]=0;			
			dfs(vis,i,now+1,all+ (fa==-1?0:cost[fa][i]));
			vis[i]=1;
		}
	
}


int main()  
{
	init();
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d\n",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int vis[M];
		memset(vis,0,sizeof(vis));
		for(char c = getchar();c!='\n';c=getchar())
			if(isalpha(c))
				vis[ch(c)]=1;
		
		min=15;
		for(int i=tot=0;i<M;++i)
			if(vis[i])
				++tot;
			
		dfs(vis,-1,0,0);
		printf("%d\n",min);
		
	};
	return 0;
};
/*
*/

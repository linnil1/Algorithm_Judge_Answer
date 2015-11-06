#include<bits/stdc++.h>
#define ll long long int


void dfs(int s,int e,int n,VMP * v)
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
	cout << dis[e] << endl ;
	
}



struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
};
#define M 2010
#define cango '.'
struct bfs
{
	char c[M][M];
	int a,b;
	int vx[4]={-1,1,0,0},
		vy[4]={0,0,-1,1};
		
	void in(int x,int y)
	{
		a=x;b=y;
		for(int i=0;i<x;++i)
			scanf("%s",c[i]);
	}
		
	int find(int x,int y)
	{
		if(c[x][y] != '.')
			return 0;
		
		for(int i=0;i<4;++i)
		{
			int tx=x+vx[i],
				ty=y+vy[i];
			if(tx>=0 && ty>=0 && tx<a && ty<b && c[tx][ty]=='.')
				;
		}
		return ;
	}
		
	int play()
	{
		std::queue<xy> q;
		
		while(q.size())
		{
			xy now=q.front();
			q.pop();
				
		}
		//printf("%d\n",all);
		if()
			return 1;
		else
			return 0;
	}
};


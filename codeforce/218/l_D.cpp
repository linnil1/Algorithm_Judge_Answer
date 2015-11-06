#include<bits/stdc++.h>
#define ll long long int

#define M 2010

char c[M][M];

int a,b;


struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
};
int vx[4]={-1,1,0,0},
	vy[4]={0,0,-1,1};
	
int find(int x,int y)
{
	if(c[x][y] != '.')
		return 0;
	
	int sum=1;
	for(int i=0;i<4;++i)
	{
		int tx=x+vx[i],
			ty=y+vy[i];
		if(tx>=0 && ty>=0 && tx<a && ty<b && c[tx][ty]=='.')
			++sum;
	}
	return sum;
}
int udlr(int x,int y)
{
	for(int i=0;i<4;++i)
	{
		int tx=x+vx[i],
			ty=y+vy[i];
		if(tx>=0 && ty>=0 && tx<a && ty<b && c[tx][ty]=='.')
			return i;
	}
	return 4;
}
	
int tonew(std::queue<xy> &q,int x,int y)
{
	if(x>=0 && y>=0 && x<a && y<b)
	{
		int t=find(x,y);
		if(t==2)
		{
			q.push(xy(x,y));
			return 1;
		}
		else if(t!=0)
			return 1;
		else
			return 0;
	};
	return 0;
};

int play()
{
	std::queue<xy> q;
	
	int all=0;
	for(int i=0;i<a;++i)
		for(int j=0;j<b;++j)
			all+=tonew(q,i,j);
			
	if(all%2)
		return 0;
				
	
	while(q.size())
	{
		xy now=q.front();
		q.pop();
		if(c[now.x][now.y]!='.')
			continue;
		all-=2;
		//u 0 d 1 l 2 r 3
		switch(udlr(now.x,now.y))
		{
			case 0:
				c[now.x][now.y]='v';
				--now.x;
				c[now.x][now.y]='^';
				break;
			case 1:
				c[now.x][now.y]='^';
				++now.x;
				c[now.x][now.y]='v';
				break;
			case 2:
				c[now.x][now.y]='>';
				--now.y;
				c[now.x][now.y]='<';
				break;
			case 3:
				c[now.x][now.y]='<';
				++now.y;
				c[now.x][now.y]='>';
				break;
			case 4:
				return 0;
		}
		
		for(int i=0;i<4;++i)
			tonew(q,now.x + vx[i], now.y+vy[i]);		
	}
	//printf("%d\n",all);
	if(all==0)
		return 1;
	else
		return 0;
}

void pr()
{
	for(int i=0;i<a;++i)
			printf("%s\n",c[i]);
}
int main()
{
	/*int T;
	scanf("%d",&T);
	while(T--)*/
	while(~scanf("%d%d",&a,&b))
	{
		for(int i=0;i<a;++i)
			scanf("%s",c[i]);
		
		if(play())
			pr();
		else
			puts("Not unique");
	};
	return 0;
};
/*
*/

#include<stdio.h>
#include<string.h>
#include<queue>
int vx[4]={0,0,+1,-1},
	vy[4]={+1,-1,0,0};
int x,y;
struct xy
{
	int x,y,val;
	xy(){};
	xy(int a,int b,int v=0){x=a;y=b;val=v;}
};

char c[100][100];
int bfs(int ex,int ey)
{
	std::queue<xy>qu;
	qu.push(xy(ex,ey));
	while(qu.size())
	{
		xy now=qu.front();
		qu.pop();
		
		for(int i=0;i<4;++i)
		{
			int tx=now.x+vx[i],
				ty=now.y+vy[i];
			if(tx>=0 && tx<x && ty>=0 && ty<y && c[tx][ty]!='@') 
			{
				qu.push(xy(tx,ty,now.val+1));
				if(c[tx][ty]=='*')
					return now.val;
				c[tx][ty]='@';
			};
		};
	}
	puts("zxc");
}

int main()
{
	int i=0,j;
	while(gets(c[i]))
		++i;
	x=i,y=strlen(c[0]);
	for(i=0;i<x;++i)
	{
		//printf("%s\n",c[i]);
		for(j=0;j<y;++j)
			if(c[i][j]=='-')
				break;
		if(j!=y)
			break;
	};
	x;
	printf("%d\n",bfs(x,y));
	
	return 0;
}


#define M 2010
#define cango '.'
struct bfs
{
	struct xy
	{
		int x,y;
		xy(){};
		xy(int _x,int _y):x(_x),y(_y){};
		
		bool operator < (const xy &b)const
		{
			if(x!=b.x)
				return x<b.x;
			else
				return y<b.y;
		}
	};
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
		if(c[x][y] != cango) 
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


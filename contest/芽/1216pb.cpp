#include<cstdio>
#include<algorithm>
int x,y,a,b;
char c[100][100];
void find()
{
	for(int i=0;i<b;++i)
		if(c[0][i]=='.')
			{x=0;y=i;return ;}
		else if(c[a-1][i]=='.')
			{x=a-1;y=i;return ;}
	for(int i=0;i<a;++i)
		if(c[i][0]=='.')
			{x=i;y=0;return ;}
		else if(c[i][b-1]=='.')
			{x=i;y=b-1;return ;}	
};
int vx[4]={0,0,1,-1},
	vy[4]={1,-1,0,0};

int dfs()
{
	c[x][y]='#';
	int i=0;
	for(i=0;i<4;++i)
	{
		int tx=x+vx[i],
			ty=y+vy[i];
			
		if(tx>=0 && ty >=0 && tx < a && ty < b && c[tx][ty]=='.')
			{x=tx,y=ty;dfs();break;}
	};
	if(i==4)
		printf("%d %d\n",x+1,y+1);
};
int main()
{
	while(~scanf("%d%d",&a,&b))
	{
		for(int i=0;i<a;++i)
				scanf("%s",c[i]);
		find();
		dfs();
			
	};
	return 0;
};

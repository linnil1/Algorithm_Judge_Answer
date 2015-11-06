#include<cstdio>
#include<algorithm>

int vx[4]={0,1,0,-1},
	vy[4]={1,0,-1,0} ;
int main()
{
	int a;
	while(~scanf("%d",&a))
	{
		int sum=a;
		int c[100][100];
		for(int i=0;i<=a+1;++i)
			for(int j=0;j<=a+1;++j)
				if(i==0 || j==0 || i==a+1 || j==a+1)
					c[i][j]=1;
				else
					c[i][j]=0;
		int now=1,x=1,y=1;
		int i=0;
		while(1)
		{
			//printf("%d %d\n",x,y);
			for( i=0;i<4;++i)
			{
				int tx=x+vx[i],
					ty=y+vy[i];
				if(!c[tx][ty])
					break;
			};
			if(i<4)
			{
				while(1)
				{
					//printf("%d %d\n",x-1,y-1);
					c[x][y]=now++;
					x+=vx[i];
					y+=vy[i];
					
					int tx=x+vx[i],
						ty=y+vy[i];
					if(c[tx][ty])
						break;									
					
				};
				
			}
			else break;
		};
		c[x][y]=now;
		for(int i=1;i<=a;++i,puts(""))
			for(int j=1;j<=a;++j)				
				printf("%3d ",(c[i][j]-1)%10);
	};
	return 0;
};

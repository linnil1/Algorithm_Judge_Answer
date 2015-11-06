#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>


int vx[4]={0,0,1,-1},
	vy[4]={1,-1,0,0};
char c[10][10];
int val[10];

int chan(char c)
{
	switch(c)
	{
		case 'R':return 0;break;
		case 'U':return 1;break;
		case 'G':return 2;break;
		case 'Y':return 3;break;
		case 'B':return 4;break;
		case 'P':return 5;break;
	}
}
int use[10][10];

int predfs(int x,int y,char ch,int &time)
{	
	use[x][y]=0;
	++time;
	for(int i=0;i<4;++i)
	{
		int tx = x +vx[i],
			ty = y +vy[i];
		if(tx>=0 && ty>=0 && tx<5 && ty<6 && ch == c[tx][ty] && use[tx][ty])
			dfs(tx,ty,ch,time);		
	}		
}
int dfs(int x,int y,char ch)
{	
	for(int i=0;i<4;++i)
	{
		int tx = x +vx[i],
			ty = y +vy[i];
		if(tx>=0 && ty>=0 && tx<5 && ty<6 && ch == c[tx][ty] )
			dfs(tx,ty,ch);		
	}
	c[x][y]=0;
		
}
void drop()
{
	for(int j=0;j<6;++j)
	{
		int now=4;
		for(int i=4;i>=0;--i)
			if(c[i][j])
				c[now--][j]=c[i][j];
				
		while(now>=0)
			c[now--][j]=0;
	}	
}


int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	#endif	
	{
		for(int i=0;i<6;++i)
			val[i]=0;
			
		for(int i=0;i<5;++i)
			scanf("%s",c[i]);
		int time=31;
		while(time--)
		{
			for(int i=0;i<5;++i)
				for(int j=0;j<6;++j)
					use[i][j] = 1;
			for(int i=0;i<5;++i)
				for(int j=0;j<6;++j)
					if(c[i][j] )
					{
						int t =  chan(c[i][j]) ;
						int time=0;
						predfs(i,j,c[i][j],time);
						
						if(time>=3)
						{
							
							dfs(i,j,c[i][j]);
							val[t] ++ ;
						}
					}
			drop();
		}
		char ch[6]={'R','U','G','Y','B','P'};
		for(int i=0;i<6;++i)
			printf("%c %d\n",ch[i],val[i]);
			
	};
	return 0;
};
/*
GPBRRR
GPBYYY
GPBUUU
UUUYYY
RRRGGG

RBRBRB
BRBRBR
RBUURB
BRGGUU
GGYYYY

*/

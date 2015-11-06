#include<bits/stdc++.h>
#define ll long long 
#define M 1010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

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
	void find(int x,int y,int& t)
	{
		c[x][y]='x';++t;
		
		for(int i=0;i<4;++i)
		{
			int tx=x+vx[i],
				ty=y+vy[i];
			if(tx>=0 && ty>=0 && tx<a && ty<b && c[tx][ty]=='J')
				c[tx][ty]='X',find(tx,ty,t);
		}
		return ;
	}
		
}bfss;

int main()
{
	//std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int x,y;
	while(~scanf("%d%d",&x,&y))
	{
		bfss.in(x,y);
		int ma=0,gr=0;
		FR(i,x)
			FR(j,y)
				if(bfss.c[i][j]=='J')
				{
					++gr;
					int t=0;
					bfss.find(i,j,t);
					ma = max(t,ma);
				}
		printf("%d %d\n",gr,ma);
	};
}
	return 0;
};
/*
10min ok
*/

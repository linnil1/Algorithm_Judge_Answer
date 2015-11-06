#include<bits/stdc++.h>
#define ll long long 
#define M 1010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define mp std::make_pair
#define VMP std::vector<MP>


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

int road[M][M][4];
int now[M][M];
/*
 0
3 1
 2
 */
int vx[4]={-1,0,1,0},
	vy[4]={0,1,0,-1};
 
void dfs(int x,int y)
{
	queue< MP > q;
	q.push( mp(x,y) );
	now[x][y]=0;
	while(q.size())
	{
		MP a = q.front();
		q.pop();
		FR(i,4)
		{
			if(!road[a.ft][a.sd][i])
				continue;
			int ax = vx[i]+a.ft,
				ay = vy[i]+a.sd;
			if( now[a.ft][a.sd] +1 < now[ax][ay])
			{
				 now[ax][ay] = now[a.ft][a.sd] +1 ;
				q.push( mp(ax,ay) );
			}
		}
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(cin >> n >> m)
	{
		
		FR(i,n)
			FR(j,m)
				road[i][j][0]=road[i][j][1]=road[i][j][2]=road[i][j][3]=1,
				now[i][j]=10080;
		FR(j,m)
			road[0][j][0]=road[n-1][j][2]=0;
		FR(i,n)
			road[i][0][3]=road[i][m-1][1]=0;
		
		int sx,sy,fx,fy ,k;
		cin >> sx >> sy >> fx >> fy >> k;
		while(k--)
		{
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1==x2)
			{
				road[x1][y1][1] = road[x2][y2][3] = 0;
				FOR(i,y1+1,y2)
					road[x1][i][1] = road[x1][i][3] = 0; 
				}
			else
			{
				road[x1][y1][2] = road[x2][y2][0] = 0;
				FOR(i,x1+1,x2)
					road[i][y1][0] = road[i][y1][2] = 0;
			}
		}
		dfs(sx,sy);
		/*FR(i,n)
		{
			FR(j,m)
				cout << now[i][j] << " ";
			cout << endl ;
		}*/
		cout << now[fx][fy] << endl ;
	};
}
	return 0;
};
/*
30min too slow

*/

char need_time=0;
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
//#include<utility>
#include<limits.h>
#define ll long long 
#define M 2510
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
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define VMP std::vector<MP>
#define MP std::pair<int,int>
#define IN(a) scanf("%d",&a)
#define INN(a,b) scanf("%d%d",&a,&b)

//using namespace std;
#define h(a,b) ((a)*22+b)

struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};

	bool in(){
		return ~scanf("%d%d",&x,&y);
	}

	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};
#define MM 2510
std::vector<xy> v[MM];

int bfs(int s,int e)
{
	int dis[MM];
	int use[MM];
	FR(i,MM)
		dis[i]=INT_MAX,	
		use[i]=1;
	dis[s]=0;
	use[s]=0;
	
	QI q;
	q.push(s);
	while(q.size())
	{
		int now = q.front(); q.pop();
		use[now]=1;
		if(now==e)
			continue;
//		for(xy& i:v[now])
		for(int ii=0;ii<v[now].size();++ii){
			xy&i =v[now][ii];
			if(dis[now]+i.y+1 < dis[i.x])
			{
				dis[i.x] = dis[now]+i.y+1;
				if(use[i.x]){
					q.push(i.x);
					use[i.x]=0;
				}
			}		
		}
	}
	return dis[e];
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	int n,m;
	while(~scanf("%d%d",&n,&m)){
		FR(i,MM)
			v[i] = std::vector<xy>();
		FR(i,n){
			int num,sum;
			INN(num,sum);
			scanf("%*d");
			FR(j,sum-1){
				int t;
				IN(t);
				v[h(num,j)].pb( xy(h(num,j+1),t) );
				v[h(num,j+1)].pb( xy(h(num,j),t) );
			}
		}
		FR(i,m){
			int sa,sb,ta,tb;
			INN(sa,sb);
			INN(ta,tb);
			--sb;--tb;
			v[h(sa,sb)].pb( xy(h(ta,tb),-1) );
			v[h(ta,tb)].pb( xy(h(sa,sb),-1) );
		}
		FR(i,5){
			scanf("%*d%*d");
			int sa,sb,ta,tb;
			INN(sa,sb);
			INN(ta,tb);
			--sb;--tb;
			printf("%d\n",bfs( h(sa,sb),h(ta,tb) ));
		}

		
		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/

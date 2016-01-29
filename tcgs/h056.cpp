char need_time=1;
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
#define M 100010
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

VMP v[1010];
int n;

bool cango(int f,int s){
	int val[n],use[n];
	FR(i,n)val[i]=INT_MAX,use[i]=1;
	val[f]=use[f]=0;
	QI q;q.push(f);
	int one=0;
	while(q.size())
	{
		int now=q.front();q.pop();
		use[now]=1;
		if(val[now]>s)
			continue;
		if(one && now==f)
		   if( val[now]<=s )
				return 1;
		   else
				continue;

		FR(i,v[now].size())
		{
			MP &k = v[now][i];
			if( val[now] + k.sd < val[k.ft])
			{
				val[k.ft] = val[now] + k.sd ;
				if(use[k.ft])
				{
					q.push(k.ft);
					use[k.ft]=0;
				}
			}
		}
		
		if(!one)
		{
			val[f]=INT_MAX;
			++one;
		}
	}
	return 0;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	int m,s;
	while(~scanf("%d%d%d",&n,&m,&s)){
		FR(i,n)
			v[i] = VMP();
		FR(i,m)
		{
			int x,y,r;
			INN(x,y);
			IN(r);
			v[x-1].pb( mp(y-1,r) );
		}

		VI ans;
		FR(i,n)
			if( cango(i,s) )
				ans.pb(i+1);
		printf("%d\n",(int)ans.size());
		if(ans.size()){
			FR(i,ans.size())
				printf("%d ",ans[i]);
			puts("");
		}

		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/

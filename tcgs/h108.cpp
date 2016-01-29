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

VI v[14];
int ans[14],anss;
int n,m;

bool comp(VI &v,int *ans,int now) {
	for(int i=0;i<v.size();++i)
		if(ans[now-1-i] != v[v.size()-1-i])
			return 0;
	return 1;
}

void dfs(int now,int con){
	if(now>=2){
		FR(j,m)
			if(v[j].size()<=now && comp(v[j],ans,now) )
				return ;
		++anss;
		if(now==n)
			return ;
	}

	for(;con<n;++con){
		ans[now]=con;
		dfs(now+1,con+1);
	}
}
				
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	while(~scanf("%d%d",&n,&m)){
		FR(i,m){
			int t;IN(t);
			v[i]=VI();
			FR(j,t){
				int k;IN(k);
				v[i].pb(k-1);
			}
		}
		anss=0;
		dfs(0,0);
		if(anss)
			printf("%d\n",anss);
		else
			puts("so sad");
		
		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/

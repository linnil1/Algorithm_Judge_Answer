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

struct xy
{
	double t[4];
	int name;

	bool operator < (const xy &b)const
	{
		return t[3] > b.t[3];
	}
}man[30];

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	int p[3];
	
	int n,m;
	while(~scanf("%d,%d",&n,&m)){
		FR(i,n){
			IN(man[i].name);
			FR(j,3)
				scanf(",%lf",man[i].t+j);
		}

		FR(i,3)p[i]=0;
		char c[1000];
		scanf("%s",c);
		for(int i=0;c[i];++i)
			switch(c[i]){
				case 's':++p[0];break;
				case 'p':++p[1];break;
				case 'c':++p[2];break;
			}

		FR(i,n){
			man[i].t[3]=0;
			FR(j,3)
				man[i].t[3]+=man[i].t[j]*p[j];
		}
		sort(man,man+n);

		double max=0;

		VI v;
		FR(i,9)
			v.pb(man[i].name),
			max += man[i].t[3];

		printf("%.3lf\n",max/9);
		sort(ALL(v));
		FR(i,8)
			printf("%d,",v[i]);
		printf("%d\n",v[8]);
		
		if(need_time && ++go_t==time)break;
	};
	return 0;
};









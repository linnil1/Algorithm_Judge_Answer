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


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	int n;
	char c[10000];
	while(~scanf("%d%s",&n,c)){
		int a=0,b=0,l=0;
		for(int i=0;c[i];++i)
			switch(c[i]){
				case 'W':a+=10;a+=l*5;l=0;break;
				case 'L':b+=10;if(l<5)++l;break;
				case 'D':a+=5;b+=5;break;
			}

		printf("%d %d\n",a,b);
		
		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/

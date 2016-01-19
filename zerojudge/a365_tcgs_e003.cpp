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

int g[1<<12];

void init(){
	FR(i,1<<12)
		g[i]=-1;
	//lose 0 win 1
	g[0]=1;
}

int play(int now){
//	printf("%d ",now);
	int t;
	if(g[now]>=0)
		return g[now];
	int mask[12]={0x30,0x18,0xC,0x300,0x180,0xC0,
				  0x12,0x110,0x900,0x9,0x88,0x480};
	for(int i=0;i<12;++i)
		if( ( (1<<i)&now) && !play( (1<<i)^now) )
			return g[now]=1;
		else if( (mask[i]&now)==mask[i] && !play(mask[i]^now) )
			return g[now]=1;
	return g[now]=0;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	init();
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	char c[15];
	int n;
	while(~scanf("%s",c)){
		for(int i=n=0;c[i];++i)
			n = n*2 + c[i]-'0';
		printf("%d",play(n));
		
	};
}
	return 0;
};
/*






*/

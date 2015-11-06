#include<bits/stdc++.h>
#define ll long long 
#define M 100100
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
#define SC(a) scanf("%d",&a);
#define PR(a) printf("%d ",a);
#define VMP std::vector<MP>
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
#define MP std::pair<int,int>
//using namespace std;
struct xy{
	int x,y,c;
};
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n)){		
		xy c[n];
		FR(i,n)
			scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].c)	;
		
		xy max= c[0];
		FOR(i,1,n)
			if( (ll)max.x*c[i].y < (ll)max.y*c[i].x)
				max = c[i];
		
		int num=0,ok=1;
		FR(i,n)			
			if( max.c != c[i].c && (ll)max.x*c[i].y == (ll)max.y*c[i].x)
				ok=0;
			else if(max.c == c[i].c)
				++num;
					
		if(!ok)
			puts("hmm, curious.");
		else
			printf("%d\n",num);
		
			
	};

	return 0;
};
/*






*/

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

int has[32][16],h[32][2],arr[16],n;

int st[16],ant[16],max;
void dfs(int now,int len,int al){
	if(now==n){
		int sum=0;
		FR(i,len)
			FR(j,al)	
				sum += __builtin_popcount( st[i] ^ ant[j]);
		
		if(sum > max)
			max = sum ;
		
		return ;
	}	
	ant[al]=arr[now];
	dfs(now+1,len,al+1);
	st[len]=arr[now];
	dfs(now+1,len+1,al); 
		
}
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	while(times-- && ~scanf("%d",&n)){		
		FR(i,n)
			scanf("%d",arr+i);
		
		/*for(int j=0;j<31;++j){
			int x = 1<< j;			
			h[j][0]=h[j][1]=0;
			FR(i,n)	
				++h[j][ has[j][i] = arr[i] & x ]; 
		}*/
			
		st[0]=arr[0];
		max=0;
		dfs(1,1,0);		
		printf("%d\n",max);
		
	};

	return 0;
};
/*

i don't know how to do it ...
and i use buildin and AC
who can tell me how to formally solve it ?

*/

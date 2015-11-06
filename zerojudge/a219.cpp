#include<bits/stdc++.h>
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
#define PR(a) cout <<  a << " " ; cout<<endl;
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

int n;
char vis[20],be[20],af[20],d[20][20];
int dfs(int now){
	if(now==n){
		//cout << i << "!";
		FR(i,n)
			if(be[i]!=af[i]){		
			printf("%c",af[i]+'A');
			be[i] = af[i ];
		}
		puts("");
		return 1;
	}
	int ok=0;
	FR(i,n)
		if(vis[i] && d[i][now]){
			vis[i] = 0;
			af[now] = i ;
			dfs(now+1);			
			vis[i] = 1;
		}
	return ok;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	while(~scanf("%d",&n)){
		memset(d,1,sizeof(d));
		FR(i,n){			
			int x;
			while(~scanf("%d",&x) && x)
				d[i][x-1]=0;
			vis[i]=1;
		}
		FR(i,n)
			be[i]=-1;
		dfs(0);
		
	};
}
	return 0;
};
/*






*/

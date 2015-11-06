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

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n)){		
	
		ARR(arr,n)
			scanf("%d",arr+i);
		ll dp[n];
		ll max = 0;
		
		//3
		dp[0]=0;
		dp[1]=arr[0];
		for(int i=2;i<n-2;++i){		
			dp[i] = MAX(dp[i-1],dp[i-2]+arr[i-1]);
		}
		max = MAX( max , dp[n-3]+ arr[n-2]);
		
		//2
		
		dp[1]=0;
		dp[2]=arr[1];
		for(int i=3;i<n-1;++i){		
			dp[i] = MAX(dp[i-1],dp[i-2]+arr[i-1]);
		}
		max = MAX( max , dp[n-2]+ arr[n-1]);
		
		//1
		
		dp[2]=0;
		dp[3]=arr[2];
		for(int i=4;i<n;++i){		
			dp[i] = MAX(dp[i-1],dp[i-2]+arr[i-1]);
		}
		max = MAX( max , dp[n-1]+ arr[0]);
		
		printf("%lld\n",max);
	};

	return 0;
};
/*






*/

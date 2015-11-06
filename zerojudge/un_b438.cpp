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

int pic[300][300][3] ,
	dp[300][300];
	
int n,m;

#define dis(a,b) (abs(a[0]-b[0])+ abs(a[1]-b[1])+abs(a[2]-b[2]) )

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int t;
	while(~scanf("%d%d%d",&t,&m,&n)){
		FR(i,n)
			FR(j,m)			
				FR(k,3)
					scanf("%d",pic[i][j]+k);
		while(t--){
			FR(i,n)
				FR(j,m)		
					dp[i][j]  = INT_MAX ;
			FR(j,m)
				dp[0][j]=0;
			FOR(i,1,n)
				FR(j,m){
					for(int dir=-1;dir<=1;++dir)
						if(j+dir >=0 && j+dir < m && 
							dp[i-1][j] + dis(pic[i-1][j],pic[i][j+dir])< dp[i][j+dir])
							dp[i][j+dir] = dp[i-1][j] + dis(pic[i-1][j],pic[i][j+dir]) ;
							
				}
			int min = INT_MAX;
			FR(j,m)
				min = MIN(min , dp[n-1][j]);
			int ans;
			for(ans=0;dp[n-1][ans]!=min;++ans);			
			FOR(j,ans+1,m)
				FR(k,3)
					pic[n-1][j-1][k] = pic[n-1][j][k] ;
			BFR(i,n-1){			
				for(int dir=-1;dir<=1;++dir)
					if(ans+dir >=0 && ans+dir < m && 
						dp[i+1][ans] - dis(pic[i+1][ans],pic[i][ans+dir]) == dp[i][ans+dir])
							ans += dir ;
				
				FOR(j,ans+1,m)
					FR(k,3)
						pic[i][j-1][k] = pic[i][j][k] ;
			}
			--m;
				
		}
		printf("%d %d\n",m,n);
		FR(i,n)
		{
		
			FR(j,m)			
				FR(k,3)
					printf("%d ",pic[i][j][k]);	
			puts("");
		}
					
	};
	
}
	return 0;
};
/*






*/

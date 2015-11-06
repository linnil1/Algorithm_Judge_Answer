#include<bits/stdc++.h>
#define ll long long 
#define M 1010
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

double dp[M],mu[M],ti[M];
double fact[M];

double c(int a,int b){
	return fact[a]/fact[b];
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	fact[0]=1;
	for(int i=1;i<M;++i)
		fact[i]=fact[i-1]*i ;
	
	
	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	int n,m;
	while(times-- && ~scanf("%d%d",&n,&m)){
		//init
		mu[1]=m;
		for(int i=1;i<m;++i)
			mu[i+1] = mu[i]*(m-i);
		for(int i=1;i<=m;++i)
			mu[i] *= i*i/fact[i] ;
		double ans = 2;
		for(int i=0;i<n;++i)
			ans*= (m*n-i); 	
			
			
		//godp		
		for(int i=0;i<=n;++i)
			dp[i]=ti[i]=0;
		dp[0]=fact[n];
		ti[0]=fact[n];
		for(int k=0;k<n;++k)
			for(int i=n;i>0;--i)
				for(int j=1;j<=m && i-j>=0;++j)
					dp[i] += dp[i-j] * mu[j] ,
					ti[i] += ti[i-j] / fact[j] ;
					 
		for(int i=0;i<=n;++i)
			cout << ti[i] << " ";
		puts("");
		
		
		printf("%.10f\n",(double)dp[n]/ans);
		
		
		
	};

	return 0;
};
/*






*/

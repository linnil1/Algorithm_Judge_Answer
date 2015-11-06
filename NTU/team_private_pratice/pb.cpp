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

struct prim{
	const static int MM=10000;
	int pr[MM],ps;
	char c[MM+1];
	void init(){
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<=MM;++i){
			if(c[i])pr[ps++]=i;
			for(int j=0;j<ps && pr[j]*i<=MM ; ++j){
				c[ pr[j]*i ] = 0 ;
				if(i%pr[j]==0)
					break;
			};			
		}
	}
	
	int isprim(int &a){		
		//be careful at 0,1 
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	
}p;

int st[M],a,b,n;
//std::list<int> li ;
int use[M];
int sum[15];
int dfs(int now){
	if(now==b-a+1)
		return 1;
	for(int i=a;i<=b;++i)
		if(use[i])
	//for(auto it = li.begin();it!=li.end();++it)
	{
			//int i = *it ;
			
			int ok=1;
			for(int j=2;j<=n && ok && now >= j-1;++j)
				if(p.c[i+sum[j]])
					ok=0;
			if(!ok)
				continue;				
			st[now]=i;
			use[i]=0;
			//it = li.erase(it) ;
			for(int j=2;j<=n;++j){			
				sum[j]+=i ;
				if(now >= j-1)
					sum[j]-=st[now-j+1];				
			}
			if(dfs(now+1))
				return 1;
			for(int j=2;j<=n;++j){			
				sum[j]-=i ;
				if(now >= j-1)
					sum[j]+=st[now-j+1];				
			}	
			use[i]=1;	
			//it=li.insert(it,i);			
		}	
	return 0;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times)
	p.init();
	while(times-- && ~scanf("%d%d%d",&a,&b,&n) && a ){	
		for(int i=a;i<=b;++i)
			use[i]=1;
		/*li.clear();
		for(int i=a;i<=b;++i)
			li.pb(i);*/
		
		FR(i,15)
			sum[i]=0;
		if( dfs(0) ){
			printf("%d",st[0]);
			FOR(i,1,b-a+1)
				printf(",%d",st[i]);
		}
		else
			printf("No anti-prime sequence exists.");
		puts("");
	};

	return 0;
};
/*






*/

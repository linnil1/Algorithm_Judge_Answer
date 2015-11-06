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

struct prim{
	const static int MM=50000;
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

int arr[70],t[70],len;

void tobase(int n){	
	len=0;
	int now = p.isprim(n);
	while(now >1 ){
		arr[len]= now ;
		t[len]=0;
		while(n%now ==0)
			++t[len],n/=now;
		//printf("%d %d\n",arr[len],t[len]);
		++len ; 
		now = p.isprim(n);
	}	
}

VI v;int lim ;

void dfs(int now,int sum){
	if(sum > lim)
		return ;
		
		
	if(now == len ){	
		v.pb(sum);
		return ;
	}
	FOR(i,-1,t[now]){
		dfs(now+1,sum);
		sum *= arr[now];
	}
		
}


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	p.init();
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		tobase(n);
		lim = (int)sqrt(n)  ; 
		v = VI();
		dfs(0,1);
		sort(ALL(v));
		for(int i=0;i<v.size();++i)
			printf("%d ",v[i]);
		if(v.back()*v.back() != n)
			printf("%d ",n/v.back());	
		for(int i=v.size()-2;i>=0;--i)
			printf("%d ",n/v[i]);	
		puts("");
		
	};
}
	return 0;
};
/*






*/

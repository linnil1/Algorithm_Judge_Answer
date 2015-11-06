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
#define MP std::pair<ll,ll>
//using namespace std;

int n,arr[M];
ll ha=28657 ,  hm = 1000000007 ;
std::map<ll,MP >map[M] ;
int st[M];

ll gohash(){
	ll now=0;
	FR(i,n)
		now =( now*ha%hm + st[i] )%hm;
	return now ;
}
MP dfs(int lay){
	//printf("%d ",lay) ; 
	ll now = gohash();
	if(map[lay].count( now ))
		return map[lay][ now ];
	ll ans=0;	
	if(lay>=n){	
		
		FR(i,n)
			ans +=st[i] * st[i] ;			
		return  mp(ans ,1);
	}
		
	ll ti=0;
	FR(i,n)
		if(arr[i]){
			--arr[i];
			++st[i];
			MP k = dfs(lay+1);
			ans += (arr[i]+1)*k.ft;
			ti  += (arr[i]+1)*k.sd;
			++arr[i];
			--st[i];
		}	
	return map[lay][now] = mp(ans,ti);
}
/*MP dfs(int lay){
	//printf("%d ",lay) ; 
	ll now = gohash();
	if(map[lay].count( now ))
		return map[lay][ now ];
	ll ans=0;	
	if(lay>=n){	
		
		FR(i,n)
			ans +=st[i] * st[i] ;			
		return  mp(ans ,1);
	}
		
	ll ti=0;
	FR(i,n)
		if(arr[i]){
			--arr[i];
			++st[i];
			MP k = dfs(lay+1);
			ans += (arr[i]+1)*k.ft;
			ti  += (arr[i]+1)*k.sd;
			++arr[i];
			--st[i];
		}	
	return map[lay][now] = mp(ans,ti);
}*/
/*
void dfs(int lay,ll ti){
	if(lay>=n){	
		t+=ti;		
		FR(i,n)
			ans +=ti* st[i] * st[i] ;			
		return  ;
	}
	
	FR(i,n)
		if(arr[i]){
			--arr[i];
			++st[i];
			dfs(lay+1,ti*(arr[i]+1));
			++arr[i];
			--st[i];
		}	
}*/
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int m;
	while(~scanf("%d%d",&n,&m)){
		FR(i,n)
			arr[i] = m ;
		FR(i,n)
			st[i]=0;
		for(int i=0;i<=n;++i)
			map[i] = std::map<ll,MP>();
		MP ans = dfs(0);
		if(n==1)
			printf("1.000000000000000\n");
		else
			printf("%.9f\n",(double)ans.ft/((ll)n*n*ans.sd));
	};
}
	return 0;
};
/*






*/

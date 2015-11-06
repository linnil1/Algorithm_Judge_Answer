#include<bits/stdc++.h>
#define ll long long 
#define M 200100
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

struct strh{
	int l ,r  ,v ,gr;
	bool operator < (const strh& b)const{
		if(gr != b.gr)
			return gr < b.gr;
		return r < b.r;
	}
}hot[M];
std::map<int,int> s;

int own[M];
ll mon[M];
int nowl, nowr;
void moteam(int l,int r,ll v ){
	while(nowr <=r )
		if(s[own[nowr++]]++==0)
			mon[ own[nowr-1] ] += v;
	while(nowl > l)
		if(s[own[--nowl]]++==0)
			mon[ own[nowl  ] ] += v;
	while(nowl < l)
		if(--s[own[nowl++]]==0){
			mon[ own[nowl-1] ] -= v;
			//s.erase( own[nowl-1] );
		}
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n,m,e;
	while(times-- && ~scanf("%d%d%d",&n,&m,&e)){		
		FRE(i,n)
			mon[i]=0;
		FRE(i,m)
			scanf("%d",&own[i]);
			
		int gap = (int)sqrt(m) ;
			
		FR(i,e){		
			scanf("%d%d%d",&hot[i].l,&hot[i].r,&hot[i].v);
			hot[i].gr = hot[i].l / gap ;
		}		
		sort(hot,hot+e);
		
		for(int i=0;i<e;){
			ll sum=0;
			int nowgr = hot[i].gr;
			nowl=nowr = hot[i].l ;
			s = std::map<int,int>() ;
			for(int j=i;j<e && nowgr == hot[j].gr;++j)
				sum += hot[j].v;
			for(i;i<e && nowgr==hot[i].gr ;++i){			
				moteam(hot[i].l,hot[i].r,sum);
				//printf("%I64d !",sum);	
				/*FRE(i,n)
					printf("%I64d ",mon[i]);
				puts("zxc");*/
				sum -= hot[i].v;
			}			
		};
		
		FRE(i,n)
			printf("%lld ",mon[i]);
		puts("");
		
	}
		

	return 0;
};
/*






*/

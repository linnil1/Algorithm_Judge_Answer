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

struct itv{
	int l,r,v,gr ;
	inline void IN(int &gap){
		scanf("%d%d%d",&l,&r,&v);
		gr = l / gap ;
	}
	bool operator < (const itv& b)const{
		if(gr!=b.gr)
			return gr < b.gr ;
		return r < b.r ;
	}
};

ll mon[M];

struct moteam{
	static const int MM = 200100;
	
	int n,m,arr[MM],gap;
	itv itm[MM];
	void init(int &_n,int &_m){
		n = _n ; m = _m ;
		for(int i=1;i<=n;++i)
			scanf("%d",arr+i);
			
		gap = (int)sqrt(n);	
		for(int i=0;i<m;++i)
			itm[i].IN(gap);
		std::sort(itm,itm+m);			
	}
	
	int s[MM] ;
	int nowr,nowl;
	void go(itv &a ,ll v){
		while( nowr <= a.r )
			if( s[arr[nowr++]]++==0)
				mon[arr[nowr-1]] += v ;
		while( nowl >  a.l )
			if( s[arr[--nowl]]++==0)
				mon[arr[nowl]  ] += v ;
		while( nowl <  a.l )
			if( --s[arr[nowl++]]==0)
				mon[arr[nowl-1]] -= v ;
			
	}	
	void main(){
		for(int i=0;i<m;){
			int nowgr = itm[i].gr ;
			nowl = nowr = itm[i].l ;
			FRE(i,n)
				s[i]=0;
			ll sum=0;
			for(int j=i;j<m && itm[j].gr == nowgr ;++j)
				sum +=itm[j].v ;
							
			for(i;i<m && itm[i].gr == nowgr ;++i){
			
				go(itm[i],sum);
				sum -=itm[i].v ;
			}
			
		}
	}	
}mt;

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n,m,e;
	while(times-- && ~scanf("%d%d%d",&n,&m,&e)){		
		FRE(i,n)
			mon[i]=0;
		mt.init(m,e);
		mt.main();
		FRE(i,n)
			printf("%lld ",mon[i]);
		puts("");
	};

	return 0;
};
/*






*/

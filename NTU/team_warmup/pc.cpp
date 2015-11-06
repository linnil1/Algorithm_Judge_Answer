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

int findlow(VMP &v,MP& a){
	int l = 0,r=v.size() ;
	while(l+1<r){
		int mid = (l+r)>>1;
		if( v[mid].ft <= a.ft && v[mid].sd < a.sd)
			l = mid ;
		else
			r = mid ;
	}
	if(r!=v.size())
		v[r] = a ;
}
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n)){		
		int arr[n+1];
		FRE(i,n)
			scanf("%d",arr+i);
		VMP v;
		FRE(i,n)
			if(i>=arr[i]){
				int now = i - arr[i] ;
				MP here = mp(now,arr[i]);
				if( !v.size() || 
				(v.back().ft <= now  &&  v.back().sd< arr[i] )  )
					v.pb( here );
				else{
					findlow(v,here);
				}
			 }
		/*for(MP &i:v)
			printf("%d %d\n",i.ft,i.sd);*/
		printf("%d\n",(int)v.size());
		
	};

	return 0;
};
/*






*/

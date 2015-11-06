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

struct xy{
	int x,y;
};
ll c2(ll a,ll b){
	return a*(a-1)/2 * b*(b-1)/2;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	xy a[4],b[4];
	while(~scanf("%d%d",&a[0].x,&a[0].y)){
		FOR(i,1,4)
			scanf("%d%d",&a[i].x,&a[i].y);
		FR(i,4)
			scanf("%d%d",&b[i].x,&b[i].y);
			
		int n = a[1].x-a[0].x+1,
			m = a[3].y-a[0].y+1;
		
		int u=a[1].x-b[1].x+1 ,
		    d=b[0].x-a[0].x+1 ,
			l=b[0].y-a[0].y+1 ,
			r=a[2].y-b[2].y+1 ;
		
		ll sum =c2(u,r) + 
				c2(u,l) +  
				c2(d,r) +
				c2(d,l) ;
				
		sum = u*d*l*r - sum + 
				c2(l,n) + c2(r,n)+ c2(u,m )+ c2(d,m );
		printf("%lld\n",sum);
			
		
	};
}
	return 0;
};
/*






*/

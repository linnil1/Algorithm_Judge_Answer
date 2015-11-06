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


struct mufa{
	static const int MM = 100100 ;
	VI v[MM];
	int pre[20][MM],n;
	
	void init(int _n){
		n = _n ;
		for(int i=0;i<=n;++i)
			v[i] = VI();
	}
	void add(int x,int& y){
		v[x].pb(y);
		//v[y].pb(x);
	}
	int dep[MM];
	
	void gofa(){
		for(int i=1;i<18;++i)
			for(int j=0;j<n;++j)//!!
				pre[i][j] = pre[i-1][ pre[i-1][j] ];
	}
	
	int findeq(int a,int b){ 
		if( dep[a] < dep[b])
			return findeq(b,a);
			
		int gap = dep[a] - dep[b] ;	
		
		for(int i=0;gap;++i,gap>>=1)
			if(gap&1)
				a = pre[i][a];
		return a;	
	}
	int findfa(int a,int b){
		if(dep[a] > dep[b])
			a = findeq(a,b);
		else if(dep[a] < dep[b])
			b = findeq(b,a);
		if(a==b)
			return a;
		for(int i=17;i>=0;--i)
			if( pre[i][a]!= pre[i][b]){
				a=pre[i][a];
				b=pre[i][b];
			}	
		return pre[0][a] ;
	}	
}fa;
#define loc(x,y) ((x)*c+y)
int map[310][310],r,c;

int arr[2*M],tmp[2*M],k;

bool con(int way){
	std::set<int> s;
	FR(i,k){
		tmp[i] = fa.pre[way][ arr[i]]  ;
		if( s.count ( tmp[i]) )
			return 1;
		else
			s.insert( tmp[i] );
	}
	FR(i,k)
		arr[i] = tmp[i];	
	return 0;	
}
bool iscon(){
	std::set<int> s;
	FR(i,k)
		if( s.count ( arr[i]) )
			return 1;
		else
			s.insert( arr[i] );
	return 0;
}
int vx[4]={0,0,-1,1},
	vy[4]={1,-1,0,0};
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d%d",&r,&c)){		
		FR(i,r)
			FR(j,c)
				scanf("%d",map[i]+j);
		fa.init( r*c );
		
		FR(i,r)
			FR(j,c){
				int max = map[i][j] ,
					mth = loc(i,j);
				FR(k,4){
					int tx = i + vx[k],
						ty = j + vy[k];
					if(tx>=0 && ty>=0 && tx < r && ty <c && map[tx][ty] > max){
						max = map[tx][ty];
						mth = loc(tx,ty);
					}
				}
				fa.pre[0][loc(i,j)] = mth;				
			}
		fa.gofa();
		
		int ts ;scanf("%d",&ts);
		while(ts--){
			scanf("%d",&k);
			FR(i,k){
				int x,y;scanf("%d%d",&x,&y);
				arr[i] = loc(x-1,y-1) ;				
			}
			int sum=0;
			for(int i=17;i>=0;--i)
				if( !con(i) )
					sum += (1<<i);
			if( !iscon() ){			
				FR(i,k)
					arr[i] = fa.pre[0][arr[i]];
				++sum;
			}
			
			if( !iscon() )
				puts("thanks to the powerpuff girls.");
			else
				printf("%d\n",sum);
		}
		puts("");
		
	};

	return 0;
};
/*






*/

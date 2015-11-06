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
int rank[110][5],n;
int st[10];
string sm;int min ;
void dfs(int now,int use){
	if(now==5){		
		int sum=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<5;++j)
				for(int k=j+1;k<5;++k)
					if( (rank[i][j]-rank[i][k] ) *
						(st[j]-st[k] ) < 0 )
							++ sum ;
		if( sum <= min){
			string s;s.resize(5);
			FR(i,5)
				s[ st[i] ] = i+'A' ;
			
			if(sum < min)
				sm = s;
			else if(s < sm)
				sm = s;
				
			min = sum ;			
		};
		return ;
	}
	
	for(int i=0;i<5;++i){
		st[now] = i ;				
		if( use & (1<<i) )
			dfs(now+1,use^(1<<i));
	}
	
}
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	while(times-- && ~scanf("%d",&n) && n){		
		char c[10];
		FR(i,n){
			scanf("%s",c);
			for(int j=0;c[j];++j)
				rank[i][ c[j]-'A' ] = j ;
		}
		min = INT_MAX;
		sm = "Z";
		dfs(0,0x1f);
		printf("%s is the median ranking with value %d.\n",sm.c_str(),min);
		
	};

	return 0;
};
/*






*/

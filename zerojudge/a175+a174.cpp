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

std::set<int> s[210];

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		FR(i,m)
			s[i] = std::set<int>();
		while(n--){
			int type;
			scanf("%d",&type);
			switch(type){
				case 1:{
					int x;scanf("%d",&x);
					s[x%m].insert( x ) ;
					break;
				}
				case 2:{
					int x;scanf("%d",&x);
					s[x%m].erase( x ) ;
					break;	
				}
				case 3:
					puts("===== s =====");
					FR(i,m){
						printf("[%03d]:",i);
						for(int j:s[i])
							printf("%d -> ",j);
						puts("NULL");
						
					}
						
					puts("===== e =====");
					break;
			}
		}
		
		
	};
}
	return 0;
};
/*






*/

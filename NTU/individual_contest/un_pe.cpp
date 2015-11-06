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

ll mu[20];
void init(){
	mu[0]=1;
	for(int i=1;i<20;++i)
		mu[i] = mu[i-1]*9 ;
}
int n;
ll go(int a,int b){
	if(b==n-1)
		return a<1 ? 1 : a ;
	else
		return a<=1 ? a : a-1;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	init();
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	char c[25];
	while(~scanf("%s",c)){
		n = strlen(c);
		for(int i=0;i<n;++i)
			c[i]-='0';
		
		ll sum=0;
		FR(i,n){	
			sum += go(c[i],i)*mu[n-i-1];
			if(c[i]==1)
				break;
		}		
		
		printf("%lld ",sum);
		FR(j,n){			
			ll now=0;			
			FR(i,n){				
				if(i==j){
					if(c[i]==1){
						for(++i;i<n;++i){
							now+= go(c[i],i)*mu[i-j-1];
							if(c[i]==1)
								break;
						};
					}
					if(j==0 && c[j]>1)
						now+= mu[n-1] ;
					break;
				}
				now+= go(c[i],i)*mu[n-i-2];
				if(c[i]==1)
					break;
				//printf("%d! ",now);
			}
			printf("%d! ",now);
			sum+=now ;			
 		}
 		printf("%lld\n",sum);
			
	};
}
	return 0;
};
/*






*/

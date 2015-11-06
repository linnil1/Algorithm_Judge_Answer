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

int mb[3]={2,7,61};
bool miller_rabin(int n){
	
	if(n!=2 && n%2==0)
		return 0;		
	if(n!=3 && n%3==0)
		return 0;	
		
	int t=0,now = n-1;
	while(now%2 ==0) 
		now>>=1,++t;
	
	for(int i=0;i<3;++i){
		ll a = mb[i]%n;
		if(a==0 || a==1 || a==n-1)
			continue;		
		
		ll sum =1;
		for(ll j=1;j<= now ; j<<=1, a=a*a%n)
			if(now& j)
				sum = sum*a %n;
				
		if(sum==1 || sum==n-1)
			continue;
		for(int j=1;j<t;++j){
			sum = sum*sum % n ;			
			if(sum == 1 )
				return 0;
			else if(sum == n-1)
				break;				
		}		
		if(sum != n-1 )
			return 0;
		
	}
	return 1;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		printf("%s½è¼Æ\n",miller_rabin(n)? "":"«D");
	};
}
	return 0;
};
/*






*/

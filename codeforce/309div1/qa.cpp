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

using std::cin;using std::cout;using std::string;
using std::sort;using std::endl;using std::swap;
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


ll inv(ll a,ll p){return a==1 ? 1 : inv(p%a,p)*(p-p/a)%MOD;}
ll fact[M],afact[M];
void initfact(){
	fact[0]=afact[0]=1;
	FOR(i,1,M){
		fact[i] = fact[i-1]*i%MOD;
		afact[i] = inv(fact[i],MOD);
	}
}
ll C(ll a,ll b){
	return fact[a]*afact[b]%MOD*afact[a-b]%MOD;
}



int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 
	initfact();
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		ll a[n];
		FR(i,n)
			cin >> a[i];
		ll sum=1,all=0 ,nowsum=1;
		FR(i,a[0])
			nowsum = nowsum * (++all) %MOD;		
		FOR(i,1,n){
			FR(j,a[i]-1)
				nowsum = nowsum * (++all)%MOD;
			sum = sum * nowsum % MOD 
				* afact[a[i]-1] % MOD *afact[all-a[i]+1] %MOD;			
			nowsum = nowsum * (++all)%MOD;
		}
		cout << sum << endl;
	};
}
	return 0;
};
/*






*/

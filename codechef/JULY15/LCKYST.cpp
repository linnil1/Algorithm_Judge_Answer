#include<bits/stdc++.h>
#define ll unsigned long long 
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
int count(ll a,int b=2){
	int sum=0;
	while(a%b==0){
		++sum;
		a/=b;
	}
	return sum;
}
ll arr[20];

void dfs(ll mu,ll now){
	if(now%10== 7 || now%100 ==74)
		return ;
	if(now>ULLONG_MAX/5)
		return ;
	ll k = 4*mu+now;
	int c = count(k);
	//cout << k << " "<< c << endl;
	//cout << c <<" ";
	arr[c] = MIN (arr[c],k);
	
	dfs(mu*10,k);
	
	k = 7*mu+now;
	c = count(k);
	//cout << c <<" ";
	arr[c] = MIN (arr[c],k);
	dfs(mu*10,k);
}


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0);
	FR(i,20)
		arr[i]=ULLONG_MAX; 
	arr[0]=1;
	for(int i=1;i<15;i+=2)
		arr[i] =arr[i+1]= arr[i-1]*4;
	/*dfs(1,0);
	arr[0]=1;
	for(int i=18;i>=0;--i)
		arr[i] = MIN(arr[i],arr[i+1]);*/
	
	/*for(int i=0;i<=13;++i)
		cout << arr[i] << endl;*/
	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	(cin >> n);{
		int dec=1;
		while(n%10 ==0 ){
			n/=10;
			dec*=10;
		}
		int c = count(n,5);
		cout << arr[c]*n*dec << endl;
	};
}
	return 0;
};
/*






*/

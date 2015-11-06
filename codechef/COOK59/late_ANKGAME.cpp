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

ll arr[M];

ll inv (ll a,ll p){ return a==1 ? a : inv(p%a,p)*(p-p/a)%MOD;}


ll fact[M],afact[M];
void initfact(){
	fact[0]=afact[0]=1;
	FOR(i,1,M){
		fact[i] = fact[i-1]*i%MOD;
		afact[i] = inv(fact[i],MOD);
	}	
}


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	initfact();
	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	int n;
	(cin >> n);{
		FR(i,n)
			cin >> arr[i];
		std::sort(arr,arr+n);
		int one;
		for(one=0;one<n && arr[one]==1;++one);
		
		if(one==n)
		{
			if(n%2)
				cout << "1\n";
			else
				cout << "0\n";
			continue;
		}
		
		ll sum=fact[n-one];
		for(int i=one;i<n; )
		{
			int j;
			for(j=i+1;j<n && arr[j]==arr[i];++j);
			sum = sum *afact[j-i] % MOD ;
			i = j ;				
		}		
		int now=1,all = n-one+1;
		ll bigsum = sum ;
		if(one&1){
			sum = ( bigsum*(all)%MOD -bigsum)%MOD;
			bigsum = bigsum*(all++)%MOD;++now;
			--one;
		}
		
		for(int i=one;i>0;i-=2){
			//cout << sum <<  " "<< bigsum <<endl;
			bigsum = bigsum * (all++) %MOD ;++now;
			sum = (sum + bigsum*(all)%MOD*afact[now]%MOD - bigsum*afact[now-1]%MOD ) %MOD;
			//cout << all << "!"<<now<<endl;
			bigsum = bigsum * (all++) %MOD ;++now;			
		}
		
		cout << (sum+MOD)%MOD << endl;
		
	};
}
	return 0;
};
/*
misunderstanding
100
6
1 1 2 1 1 2
3
1 1 2
2
2 3

*/

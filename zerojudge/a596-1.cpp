#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 12345
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


#define lowbit(a) (a&-a)
struct  bit{
	const static int MM = 1000000;
	ll arr[MM];
	int n;//1<= <=n
	void init(int _n){
		n=1;
		while(_n){
			n<<=1;
			_n>>=1;
		}
		for(int i=1;i<=n;++i)
			arr[i]=0;
	}
	ll ask(int i){//a<= <=b
		if(i<1)
			return 0;
		ll sum=0;
		while(i){
			sum += arr[i];
			i ^= lowbit(i);			
		}
		return sum%MOD;
	}
	ll gsum(int a,int b){
		return ask(b)-ask(a-1);
	}
	
	void modi(int i,int v){
		while(i<=n){
			arr[i]+= v ;
			i += lowbit(i);
		}
	}
	
}up,down;

int scat(int *arr,int n){
	std::map<int,int> m ;
	FR(i,n)
		m[arr[i]];
	int len=0;
	for(auto &i:m)
		i.sd=++len;
	FR(i,n)
		arr[i] = m[arr[i]];	
	return len ;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		int arr[1600];		
		FR(i,n)
			scanf("%d",arr+i);
		int mm = scat(arr,n);		
		up.init(mm);
		down.init(mm);
		int coun[mm+2];
		FRE(i,mm)
			coun[i]=0;
		FR(i,n){
			int &x =arr[i];
			coun[x]++;
			ll cu = down.gsum(x+1,mm),
				cd = up.gsum(1,x-1);
			
			up.modi(x,cu+1);
			down.modi(x,cd+1);			
		}
		
		ll sum = up.gsum(1,mm)+down.gsum(1,mm) ;
		//cout << sum << endl;
		//printf("%I64d\n",sum);
		FR(i,n)
			sum -= ( n-i-1 - --coun[arr[i]]);
		sum -= 2*n;
		printf("%lld\n",(sum%MOD+MOD)%MOD);
		
		
	};
}
	return 0;
};
/*






*/

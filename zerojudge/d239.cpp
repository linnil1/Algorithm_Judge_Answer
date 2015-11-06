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

struct prim
{
	const static int MM=100000;
	int pr[MM/10],ps;
	char c[MM+1];
	void init()
	{
		//puts("zxc");
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<=MM;++i)
		{
			if(c[i])pr[ps++]=i;
			for(int j=0;j<ps && pr[j]*i<=MM ; ++j)
			{
				c[ pr[j]*i ] = 0 ;
				if(i%pr[j]==0)
					break;
			};
			
		}
	}
	
	int isprim(int &a)
	{		
		//be careful at 0,1 
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	int num(int a){
		int sum=0;
		while(1){
			int k = isprim(a);
			if(k==a)
				break;
			++sum;
			while(a%k==0)
				a/=k;
		}
		
		return sum + (a>1);
	}
	
	
}p;

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	cout << 134046-3 << endl;
	/*p.init();
	int n;
	while(cin >> n){
		//cout << p.num(n) << endl;
		int arr[4];
		FR(i,4)
			arr[i] = p.num(1000000-4+i);
		for(int i=1000000;;++i){
			int t = p.num(i);
			FOR(i,1,4)
				arr[i-1] = arr[i] ;
			arr[3] = t ;
			int ok=1;
			FR(i,4)
				if(arr[i]!=4)
					ok=0;
			if(ok){
				
				cout << i << endl;
				cin >> n ;
			}
		}
	};*/
}
	return 0;
};
/*






*/

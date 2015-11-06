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
int vis[20];
void dfs(int k,int now){
	if(k>9){
		cout << now << endl ;
		cin >> k ;
	}
	FRE(i,9)
		if(!vis[i]){
			if((now*10+i )%k)
				continue;
			vis[i]=1;
			dfs(k+1,now*10+i);
			vis[i]=0;
		}
	
	
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	cout << 381654729 << endl;
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
/*{	
	int n;
	while(cin >> n){
		memset(vis,0,sizeof(vis));
		dfs(1,0);
	};
}*/
	return 0;
};
/*






*/

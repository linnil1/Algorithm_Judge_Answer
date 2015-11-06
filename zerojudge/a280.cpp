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

VI v[M];
int vis[M];
int dfs(int now){
	for(int &i : v[now])
		if(!vis[i]){
			vis[i]=1;
			dfs(i);
		}
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,k;
	while(cin >> n >> k){
		for(int i=0;i<=100;++i)
			v[i] = VI(),
			vis[i]=0;
		
		while(k--){
			int x,y;cin >> x >> y;
			v[x].pb( y );
		}
		dfs(0);		
		if(vis[n])
			cout << "Ok!";
		else
			cout << "Impossib1e!";
		cout << endl;
		
	};
}
	return 0;
};
/*






*/

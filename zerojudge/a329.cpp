#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1234567
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

VI vr[M];int con[M];



ll val[M];

void bfs(int n){
	FRE(i,n)
		val[i]=0;
	val[1]=1;
	QI q;	
	FRE(i,n)
		if(con[i]==0)
			q.push( i );
	while(q.size()){
		int now = q.front();q.pop();
		if(now==n )
			continue;
		for(int &i : vr[now]){
			if(--con[i]==0)
				q.push(i);
			val[i] = (val[i]+val[now])%MOD;
		}
		val[now]=0;			
	}
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		FRE(i,n)
			vr[i] = VI(),
			con[i] = 0;
		FRE(i,n){
			int x,y;cin >> x;
			while(x--){
				cin >> y;
				++con[y];
				vr[i].pb(y);
			}
		}
		bfs(n);			
		cout << val[n] << endl;
	};
}
	return 0;
};
/*

3
2 2 3  
2 3 3 
0    
8
5 8 2 4 2 3 
6 5 3 3 3 7 3 
5 6 7 7 7 4 
4 7 5 8 5 
5 6 6 6 7 8 
1 7 
3 8 8 8 
0



*/

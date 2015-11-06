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

string c[5][2] = {{"*   ","*** "},{"    ","****"},{"  * ","*** "},{"**  ","**  "},{"*** "," *  "}};

int arr[20],vis[20],sum=0;

void dfs(int now,int &n){
	if(now==n){
		++sum;
		FR(i,n){	
			cout << c[ arr[i]][0]<<"|" ;			
		}
		cout << endl;
		FR(i,n){	
			cout << c[ arr[i]][1] <<"|";			
		}
		cout << endl << endl;
		return ;
	}
	for(int i=0;i<5;++i)
		if(vis[i] && (!now|| arr[now-1]!=i)){
			arr[now]=i;
			--vis[i];
			dfs(now+1,n);
			++vis[i];
		}
}
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(cin >> n>>m){
		FR(i,5)
			vis[i]=m;
		sum=0;
		dfs(0,n);
		cout << "Sum : " << sum <<endl;
	};
}
	return 0;
};
/*
forget to sum=0;





*/

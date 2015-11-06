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

int dp[50][50] ;
int od[50][50];
string sa,sb;
char ans[50];
std::set<string> ss;

void dfs(int a,int b,int now){
	if(a==sa.size() || b==sb.size() || now==dp[0][0]){		
		if(now==dp[0][0])
			//cout << ans << endl;
			ss.insert(ans);
		return ;
	}
	if(dp[a][b] != dp[a+1][b+1] && sa[a]==sb[b]){
		ans[now] = sa[a];
		dfs(a+1,b+1,now+1);
	}
	if(od[a][b+1]!=-1 )
		dfs(a,od[a][b+1],now);
	if(dp[a][b] == dp[a+1][b])
		dfs(a+1,b,now);
}



int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	string &a=sa,&b=sb;
	(cin >> a>>b);{
		
		memset(dp,0,sizeof(dp));
		memset(od,-1,sizeof(od));
		BFR(i,a.size())
			BFR(j,b.size()){
				dp[i][j] = MAX(dp[i+1][j],dp[i][j+1]);
				dp[i][j] = MAX(dp[i][j],dp[i+1][j+1] + (a[i]==b[j]));
				if(a[i]==b[j])
					for(int k=0;k<=j;++k)
						od[i][k]=j;
			}
		/*FR(i,a.size()){
			FR(j,b.size())
				cout << dp[i][j] << " ";
			cout << endl;
		}*/
		ans[dp[0][0]]='\0';
		ss = std::set<string>();
		dfs(0,0,0);
		cout << "Case #" << cases<< ": "<<ss.size() << endl;
		for(string a:ss)
			cout << a << endl;
	};
}
	return 0;
};
/*
abcabcaa
acbacba
abcdfgh
abccfdsg
3124158592654359
3173415926581359





*/


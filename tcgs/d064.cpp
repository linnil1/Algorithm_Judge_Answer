//#include<bits/stdc++.h>

#include<cstdio>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
//#include<utility>
#include<limits.h>
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
#define VMP std::vector<MP>
#define MP std::pair<int,int>
#define IN(a)int a; scanf("%d",&a)
#define INN(a,b)int a,b; scanf("%d%d",&a,&b)

//using namespace std;
string max;
int use[3];
void dfs(int t,string *s,string now){
	if(t==3){
		if(now > max )
			max = now;
		return ;
	}
	FR(i,3)
		if(use[i]){
			use[i]=0;
			dfs(t+1,s,now+s[i]);
			use[i]=1;
		}
}
	
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	string s[3];
	while(cin>>s[0]>>s[1]>>s[2]){
		max="";
		memset(use,1,sizeof(use));
		dfs(0,s,"");
		cout << max<<endl;

		
	};
}
	return 0;
};
/*






*/

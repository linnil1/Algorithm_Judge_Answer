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
#define IN(a) scanf("%d",&a)
#define INN(a,b) scanf("%d%d",&a,&b)

//using namespace std;


struct disjointset
{
	static const int MM=10100;
	int s[MM],n,group;
	
	void init(int _n){
		group = n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	};	
	inline int find(int a){
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b){
		if(find(a)!=find(b)){
			s[find(a)] = find(b);
			--group;
			return 1;
		}
		else
			return 0;
	}	
	
}disj;


struct xy{
	int s,t,v;
	bool operator < (const xy &a)const{
		return v <a.v;
	}
};





int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		std::map<string,int> map;
		string s[n];
		FR(i,n){
			cin >> s[i];
			map[s[i]]=i;
		}
		
		xy r[m];
		FR(i,m){
			string t;
			cin >> t; r[i].s=map[t];
			cin >> t; r[i].t=map[t];
			IN(r[i].v);
		}
		sort(r,r+m);

		int sum=0,now=0;
		disj.init(n);
		MP ans[n-1];
		for(int i=0;i<m&& disj.group>1;++i)
			if(disj.unin(r[i].s,r[i].t)){
				sum+=r[i].v;
				ans[now++] = mp(r[i].s,r[i].t);
			}
		sort(ans,ans+n-1);
		FR(i,n-1)
			cout << "(" << s[ans[i].ft] <<" "<<s[ans[i].sd]<<")";
		printf("\n%d\n",sum);




	};
}
	return 0;
};
/*






*/

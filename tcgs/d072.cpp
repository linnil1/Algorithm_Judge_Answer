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
#define MP std::pair<string,int>
#define IN(a) scanf("%d",&a)
#define INN(a,b) scanf("%d%d",&a,&b)

//using namespace std;

VMP where,ani[2000];
int anow;

void goaddwh(string wh,string a,int ti){
	for(int tti=0;tti<where.size();++tti){
		MP &i = where[tti];
		if(i.ft == wh){
			FR(ttj,ani[i.sd].size()){
				MP &j=ani[i.sd][ttj];	
				if(j.ft == a){
					j.sd +=ti;
					return ;
				}
			}
			ani[i.sd].pb(mp(a,ti));
			return ;
		}
	}
	where.pb(mp(wh,anow));
	ani[anow]=VMP();
	ani[anow++].pb(mp(a,ti));
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		where=VMP();
		anow=0;
		FR(i,n){
			string a,wh;
			int ti;
			cin >> a >> ti >> wh ;
			goaddwh(wh,a,ti);
		}
		
		FR(tti,where.size()){
			MP &i = where[tti];
			int tmp=0;
			cout << i.ft <<":";
			FR(ttj,ani[i.sd].size()){
				MP &j = ani[i.sd][ttj];
				if(tmp++)
					cout <<',';
				cout << j.ft << " " << j.sd;
			}
			puts("");
		}
	};
}
	return 0;
};
/*






*/

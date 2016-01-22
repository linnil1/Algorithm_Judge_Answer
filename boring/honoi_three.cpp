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

void ori(int ,char ,char ,char );
void spec(int ,char ,char ,char );

int want,sum;
void ori(int who,char a,char b,char c){
	if(who<=0)return ;
	ori(who-1,a,c,b);
	printf("ring %d : %c => %c\n",who,a,c);
	++sum;
	if(who==want)
		return ;
	ori(who-1,b,a,c);
}

void spec(int who){
	char now=0;
	sum=0;
	for(int i=who;i>=1;--i){
		want = i;
		int tar =(i+2)%3 ;
		if(now==tar)
			continue;
		ori(i,now+'A',3-tar-now+'A',tar+'A');
		now= 3-tar-now;
	}
	printf("共需%d個移動\n",sum); 
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		spec(n);	
	};
}
	return 0;
};
/*






*/

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
#define IN(a) int a; scanf("%d",&a)
#define INN(a,b) int a,b; scanf("%d%d",&a,&b)

//using namespace std;


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int a[3],b[3];
	while(~scanf("%d:%d:%d",b,b+1,b+2)){
		scanf("%d:%d:%d",a,a+1,a+2);
		for(int i=2;i>0;--i){
			a[i]-=b[i];
			if(a[i]<0){
				a[i]+=60;
				--a[i-1];
			}
		}
		a[0]-=b[0];
		if(a[0]<0)
			a[0]+=24;
		printf("%02d:%02d:%02d\n",a[0],a[1],a[2]);
		
	};
}
	return 0;
};
/*






*/

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
char ans[1000],c[1000],anss;
void in_post(int &now){//(A+B*(C-D)+E)*((F+G)/(H*I)+J)
	char st[2]={0};
	for(now;c[now];++now)
		if(c[now]=='('){
			++now;
			in_post(now);
			if(st[1])
				ans[anss++]=st[1];
			st[1]=0;
		}
		else if(c[now]==')')
			break;
		else if(c[now]=='*'||c[now]=='/'){
			if(st[1])
				ans[anss++]=st[1];
			st[1]=c[now];
		}
		else if(c[now]=='+'||c[now]=='-'){
			BFR(i,2)
				if(st[i]){
					ans[anss++]=st[i];
					st[i]=0;
				}
			st[0] = c[now] ;
		}
		else
			ans[anss++]=c[now];
	BFR(i,2)
		if(st[i]){
			ans[anss++]=st[i];
			st[i]=0;
		}
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	while(~scanf("%s",c)){
		int now=0;anss=0;
		in_post(now);
		ans[anss++]='\0';
		printf("%s\n",ans);
		
	};
}
	return 0;
};
/*






*/

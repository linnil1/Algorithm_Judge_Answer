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
#define MP std::pair<ll,ll>
//using namespace std;

MP go(char *a){
	ll now=0;int mu=1;
		int i;
		for(i=0;a[i]&& !isdigit(a[i]);++i)
			if(a[i]=='-')
				mu=-1;
		for(i;a[i] && isdigit(a[i]);++i)
			now = now*10 + a[i]-'0';
		now *=mu;
		
		ll com=0;mu=1;
		for(i;a[i]&& !isdigit(a[i]);++i)
			if(a[i]=='-')
				mu=-1;
		for(i;a[i] && isdigit(a[i]);++i)
			com = com*10 + a[i]-'0';
		com *=mu;
	return mp(now,com);
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	char a[M],b[M] ;
	(~scanf("%s%s",a,b));{
		MP ma = go(a),
			mb = go(b);
		printf("%d%+di\n",ma.ft+mb.ft , ma.sd+mb.sd);
		
	};
}
	return 0;
};
/*






*/

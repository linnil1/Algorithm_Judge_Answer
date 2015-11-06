#include<bits/stdc++.h>
#define ll long long 
#define M 100100
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
#define SC(a) scanf("%d",&a);
#define PR(a) printf("%d ",a);
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
#define MP std::pair<int,int>
//using namespace std;
int test,m;
int hash(const char *s) {
	int h = 0;
	for (int i = 0; s[i]; i++) 
		h = (h * test + s[i] - 'a' + 1) % m;
	return h;
}
char a[M],b[M];
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	
	while(times-- && scanf("%s%s%d",a,b,&m)){
		if(strcmp(a,b)==0){		
			printf("%d\n",m-1);		
			continue;
		};
		int ans=0;
		for(test=0;test<=m-1/*MIN(25,m-1)*/;++test)
			if(hash(a) == hash(b))
				++ans,printf("%d ",test);
		printf("%d\n",ans);
		
	};

	return 0;
};
/*






*/

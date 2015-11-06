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
#define MP std::pair<int,int>
//using namespace std;
int ok=0;
void test(int a,int b,int ar,int ac,int br,int bc){
	if(ok)
		return ;
	if(a<ar || b < ac)
		return ;
	if(br>a || bc > b)
		return ;
	ar = a-ar ; ac = b-ac;
	if( br >ar && bc >ac)
		ok=0;
	else
		ok=1;
		
}
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	int a,b,ar,ac,br,bc;
	while(times-- && ~scanf("%d%d",&a,&b)){		
		if(a>b)
			swap(a,b);
		scanf("%d%d%d%d",&ar,&ac,&br,&bc);
		ok=0;
		
		test(a,b,ar,ac,br,bc);	
		test(a,b,ac,ar,br,bc);	
		test(a,b,ar,ac,bc,br);	
		test(a,b,ac,ar,bc,br);	
		
		printf("%s\n",ok?"YES":"NO");
	};

	return 0;
};
/*






*/

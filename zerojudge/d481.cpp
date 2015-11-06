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
#define matM 110
struct mat
{
	ll m[matM][matM];
	int r,c;
/*
r=2 c=3
xxx
xxx
*/
	mat(){};
	mat(int _r,int _c):r(_r),c(_c){memset(m,0,sizeof(m));};

};
mat operator * (mat a,mat b)
{
	if(a.c != b.r)
		puts("error");
	mat c(a.r,b.c);
	for(int i=0;i<c.r;++i)
		for(int j=0;j<c.c;++j)
			for(int k=0;k<a.c;++k)
				c.m[i][j] = ( c.m[i][j] + a.m[i][k]*b.m[k][j] );
	return c;
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int ar,ac,br,bc;
	while(cin >> ar >> ac >> br >> bc){
		if(ac!=br){
			cout << "Error\n";
			continue;
		}		
		mat ma(ar,ac),mb(br,bc);
		FR(i,ar)
			FR(j,ac)
				cin >> ma.m[i][j];
		FR(i,br)
			FR(j,bc)
				cin >> mb.m[i][j];
		
		mat mc = ma*mb;
		FR(i,mc.r){
			FR(j,mc.c)
				cout << mc.m[i][j] << " ";
			cout << endl;
		}
	};
}
	return 0;
};
/*






*/

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

int pic[300][300][3];

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int w,h;
	while(cin >> w >> h){
		FR(i,h)
			FR(j,w)
				FR(k,3)
					cin >> pic[i][j][k] ;
		FR(i,h)
			FR(k,3)
				pic[i][w][k]=pic[i][w-1][k];
		FR(j,w)
			FR(k,3)
				pic[h][j][k]=pic[h-1][j][k];
		FR(i,h)
			FR(j,w)
				FR(k,3){
					int t = abs(pic[i+1][j][k]-pic[i][j][k] )+ 
							abs(pic[i][j+1][k]-pic[i][j][k] );
					pic[i][j][k] = t&1 ? t/2+1 : t/2 ;
				}
		cout << w <<" " << h << endl;
		FR(i,h){
			FR(j,w)
				FR(k,3)
					cout << pic[i][j][k] <<" ";
			cout << endl;
		}
	};
}
	return 0;
};
/*






*/

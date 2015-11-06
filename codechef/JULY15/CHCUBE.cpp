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

string s[6];

#define com(a,b,c)  (s[a]==s[b] && s[b]== s[c]) 


bool check(){
	if ( com(0,3,4) || com(0,3,5)||
	 com(0,2,5) ||com(0,2,4) ||
	 com(1,3,4) ||com(1,2,4) ||
	 com(1,2,5) || com(1,3,5) )
	 	return 1;
	else
		return 0;
}
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	{
		FR(i,6)
			cin >> s[i];
		cout << (check()?"YES":"NO") << endl;
	};
}
	return 0;
};
/*






*/

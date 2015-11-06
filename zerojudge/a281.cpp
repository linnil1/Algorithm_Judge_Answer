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
#define MP std::pair<ll,int>
//using namespace std;


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int money,n;
	while(cin >> money >> n){
		VMP v;
		while(n--){
			int s,h,i,k;cin >> s >> h >> i >> k;
			ll sum=0,cost=0,wei=0;
			FR(j,i){
				int a,b,c,d,e; cin >> a>>b>>c>>d>>e;
				sum += c*b ;
				cost += a*e;
				wei += d*e;
			}
			if(s>money)
				continue;
			v.pb( mp( sum*wei/k/cost  ,s) );
		}
		std::sort(ALL(v));
		/*FR(i,v.size())
			cout << v[i].ft <<" "<<v[i].sd<< endl;*/
		
		cout << money - v.back().sd << endl;
	};
}
	return 0;
};
/*

C/P     琌		瞶单/Θセ
Θセ      ﹚竡	羆禣/籹Θ计
瞶单  		キА单*贺摸计
单  		蔼祘*穝翧

*/

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
struct disjointset
{
	static const int MM=10100;
	int s[MM],n,group;
	void init(int _n)
	{
		group = n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	};
	
	inline int find(int a)
	{
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b)
	{
		if(find(a)!=find(b))
		{
			s[find(a)] = find(b);
			--group;
			return 1;
		}
		else
			return 0;
	}	
	
}disj;


struct xy{
	int s,t,v;
	bool operator < (const xy &a)const{
		return v <a.v;
	}
};





int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(cin >> n >> m){
		xy arr[m];
		FR(i,m)
			cin >> arr[i].s >> arr[i].t >> arr[i].v;
		std::sort(arr,arr+m);
		ll sum=0;
		disj.init(n);
		for(int i=0;i<m && disj.group>1 ; ++i)
			if( disj.unin(arr[i].s,arr[i].t))
				sum += arr[i].v;
		cout << sum << endl;
		
	};
}
	return 0;
};
/*






*/

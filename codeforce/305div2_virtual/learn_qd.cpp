#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define FORE(i,a,n) for(int i=a;i<=n;++i)
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


int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		ARR(arr,n)
			cin >> arr[i];
		int f[n],b[n];
		
		std::stack< MP > s;
		FR(i,n)
		{
			while(s.size() && arr[i] <= s.top().ft )
				s.pop();
			f[i] = s.size() ? s.top().sd : -1 ; 			
			s.push( mp(arr[i],i) );
		}
		s = std::stack<MP>();
		BFR(i,n)
		{
			while(s.size() && arr[i] <= s.top().ft )
				s.pop();
			b[i] = s.size() ? s.top().sd : n ; 			
			s.push( mp(arr[i],i) );
		}
		
		ARR(max,n)max[i]=0;
		FR(i,n)
		{
			max[ b[i]-f[i]-2 ] = MAX( max[b[i]-f[i]-2] , arr[i] );
		}
		int now=0;
		BFR(i,n)
		{
			 max[i] = now = MAX(max[i],now);
		}
		FR(i,n)
			cout << max[i] << " ";
		cout<<endl;
		
		
	};
}
	return 0;
};
/*






*/

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
using std::sort;using std::endl;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MANN(a,b,c) MIN(MIN(a,b),c)


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
		if(n%2==0)
		{
			cout << "NO\n";
			continue;
		}
		cout <<"YES\n";
#define out(a,b) cout << a << " " << b << "\n"

#define bout(a,b) {out(a,b); out(a+2*n-1,b+2*n-1);}
		out( 4*n-2 , n*(2*n-1));
		for(int i=2;i<=n-1;i+=2)
		{		
			bout ( i-1 , i);
		}
		
		for(int i=1;i<=n-1;++i)
			for(int j=n;j<=2*n-2;++j)
				bout (i,j);
				
		for(int j=n;j<=2*n-2;++j)
			bout (j,2*n-1);
		
		out(2*n-1,4*n-2);		
	
	};
	
}
	return 0;
};
/*






*/

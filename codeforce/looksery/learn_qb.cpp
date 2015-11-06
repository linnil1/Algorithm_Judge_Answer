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
		char a[n][n*4];
		FR(i,n)
		{
			cin >> a[i];
			FR(j,n)
				a[i][j]-='0';
		}
		VI v;
		ARR(no,n) cin>>no[i];
		ARR(wa,n) wa[i]=0;
		FR(i,n)
		{
			int k=-1;
			FR(j,n)
				if(no[j]==wa[j])
				{
					v.pb(j);
					k=j;break;
				}
			if(k==-1)
				break;
			FR(j,n)
				wa[j]+=a[k][j];
		}
		int ok=1;
		FR(j,n)
			if(no[j]==wa[j])
				ok=0;
		if(ok)
		{
			cout << v.size() << endl;
			FR(i,v.size())
				cout << v[i]+1 << " ";
		}
		else
			cout << -1;
		cout << endl;
		
	};
}
	return 0;
};
/*






*/

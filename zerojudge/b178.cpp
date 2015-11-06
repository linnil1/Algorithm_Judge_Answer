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
		MP arr[n];
		FR(i,n)
		{
			int x,y;
			cin >> x >> y;
			arr[i] = mp(x,y);
		}
		std::sort(arr,arr+n);
		
		MP port[n];
		int len=0;
		
		FR(i,n)
		{
			int j=0;
			for(j;j<len;++j)
			{
				if(arr[i].sd < port[j].ft)
				{				
					port[j].ft = arr[i].sd;
					break;
				}
				if(arr[i].sd < port[j].sd && arr[i].ft > port[j].ft)
				{				
					port[j].ft = arr[i].sd;
					break;
				}
				if(arr[i].ft > port[j].sd)
				{
					port[j] = mp(arr[i].sd ,arr[i].sd);
					break;
				}
				
			}			
			if(j==len)
				port[len++] = mp(arr[i].sd ,arr[i].sd);
		}
		cout << len << endl;
	};
}
	return 0;
};
/*






*/

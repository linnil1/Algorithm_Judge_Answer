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

int c[510][510];

void modi(int *arr,int m,int &max)
{
	int k=0;
	max=0;
	FR(j,m)
	{			
		if(arr[j]!=1)	
		{
			if(k>max)
				max = k ;			
			k=0;
		}
		else
			++k;					
	}
	if(k > max)
		max = k ;
	//cout << max << "!" ;
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m,q;
	while(cin >> n >> m >> q)
	{
		
		FR(i,n)
			FR(j,m)
				cin >> c[i][j];		
		int max[n];
		FR(i,n)
			modi(c[i],m,max[i]);
		while(q--)
		{
			int x,y;
			cin >> x >> y;
			--x;--y;
			c[x][y]^=1;
			
			modi(c[x],m,max[x]);
				
			int mm=0;
			FR(i,n)
				if(max[i]>mm)
					mm = max[i];
			cout << mm << endl ;		
		}
	};
}
	return 0;
};
/*






*/

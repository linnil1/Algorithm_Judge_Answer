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
	int n,m;
	while(cin >> n >> m)
	{
		char c[110][110];
		int now[110][110];
		FR(i,n)
		{
			cin >> c[i];
			FR(j,m)
				now[i][j]=0;
		}
		int t=0;
		BFR(i,n)
			BFR(j,m)
			{
				if(i) now[i-1][j]+=now[i][j];
				if(c[i][j]=='B'&&now[i][j]!=-1)
				{
					int k=-1-now[i][j];
					for(int q=0;q<j;++q)
						now[i][q]+=k;
					if(i)now[i-1][j]+=k;
					++t;
				}
				else if(c[i][j]=='W'&&now[i][j]!=1)
				{
					int k=1-now[i][j];
					for(int q=0;q<j;++q)
						now[i][q]+=k;
					if(i)now[i-1][j]+=k;
					++t;
				}
			}
		cout << t << endl;
	};
}
	return 0;
};
/*

i don't know what are the question about




*/

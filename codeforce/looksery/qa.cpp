#include<bits/stdc++.h>
#define ll long long 
#define M 1010
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

char ch[M][M];

int check(int i,int j)
{
	switch(ch[i][j])
	{
		case 'f':return 1<<0;
		case 'a':return 1<<1;
		case 'c':return 1<<2;
		case 'e':return 1<<3;
		default :return 0;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(cin >> n >> m)
	{
		FR(i,n)
			cin>> ch[i];
		int sum=0;
		FOR(i,1,n)
			FOR(j,1,m)
				if((check(i-1,j-1)^check(i-1,j)^check(i,j-1)^check(i,j))==15)
					++sum;
		cout << sum << endl;
	};
}
	return 0;
};
/*






*/

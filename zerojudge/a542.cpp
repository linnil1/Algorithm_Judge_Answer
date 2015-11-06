#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 100000007 
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


ll arr[15][15],ans[1<<12];
ll go(int now,int n,int use)
{
	if(ans[use]!=-1)
		return ans[use];
	if(now+1==n)
	{
		FR(i,n)
			if(use & (1<<i))
				return arr[now][i]; 
	}
	ll sum=0;
	int pm=0;
	FR(i,n)
		if(use & (1<<i))
		{
			pm++;
			sum = sum+ (pm%2?1:-1)*arr[now][i]*go(now+1,n,use^(1<<i))%MOD ;
			sum = (sum%MOD+MOD)%MOD;
		}
	
	return ans[use]=sum ;
}


int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		FR(i,n)
			FR(j,n)
				cin >> arr[i][j];
		FR(i,1<<n)
			ans[i]=-1;
		cout << go(0,n,(1<<n)-1) << endl ;
	};
}
	return 0;
};
/*






*/

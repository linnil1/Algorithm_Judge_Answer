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

int arr[16],l,r,x,ans;

void dfs(int now,int tot,int len,int max,int min)
{
	if(r<tot)
		return ;
	if(now<0)
	{
		if(2<=len && l<=tot && tot <= r && max-min>=x)
			++ans;
		return ;
	}
	dfs(now-1,tot,len,max,min);
	
	dfs(now-1,tot+arr[now],len+1,MAX(max,arr[now]),MIN(min,arr[now]));
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n >> l >> r >> x)
	{
		FR(i,n)
			cin >> arr[i];
		
		ans=0;
		dfs(n-1,0,0,INT_MIN,INT_MAX);
		
		cout  << ans << endl;
			
	};
}
	return 0;
};
/*






*/

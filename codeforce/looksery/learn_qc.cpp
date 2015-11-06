#include<bits/stdc++.h>
#define ll long long 
#define M 200010
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

int arr[M];

int cal(int all,int city,int odd,int even)
{
	if(all == city)
		return odd%2==1;
	if(city==0)
		return 0;
	
	int now = (all-city);
	
	if(now%2==1)
	{
		if(city%2==0)
			if(now/2 >= odd || now/2 >=even)
				return 0;
		if(city%2==1)
			if(now/2>=odd)
				return 0;
		return 1;
	}
	else
	{
		if(city%2==0)
			return 0;
		else if(now/2 >= even)
			return 1;	
		return 0;
	}
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(cin >> n >> m)
	{
		int odd=0,even=0;
		FR(i,n){
			int x;cin >> x;
			if(x%2)
				++odd;
			else
				++even;
		}
		cout << (cal(n,m,odd,even)?"Stannis":"Daenerys") << endl;
	};
}
	return 0;
};
/*






*/

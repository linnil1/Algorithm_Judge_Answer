#include<bits/stdc++.h>
#define ll long long 
#define M 10010
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


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

int front[M];
struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	bool operator < (const xy &b)const
	{
		if(y!=b.y)
			return y>b.y;
		else
			return x>b.x;
	}
};

int where(int a)
{
	return front[a]==a? a : front[a] = where(front[a]);
}

int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		xy arr[n];
		for(int i=0;i<n;++i)
			cin >> arr[i].x >> arr[i].y ;
		std::sort(arr,arr+n);
		ll sum=0;
		FR(i,M)
			front[i]=i;
		FR(i,n)
		{
			int now = where(arr[i].x);
			if(now<=0)
				continue;
			--front[now];
			sum+=arr[i].y;
		}
		cout << sum <<endl;
	};
}
	return 0;
};
/*
16min 
debug (now) and the cin_scanf problem and the front[0]=0;
*/

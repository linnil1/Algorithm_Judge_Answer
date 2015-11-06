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


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

struct package
{
	int pack[M],n;
	void init(int _n)
	{
		n = _n;
		for(int i=0;i<=n;++i)
			pack[i]=0;
	}
	void zero(int cost,int val)
	{
		for(int i=n-cost;i>=0;--i)
			if(pack[i+cost] < pack[i]+val )
				pack[i+cost] = pack[i]+val;
	}
	void mult(int cost,int val)
	{
		for(int i=cost;i<=n;++i)
			if(pack[i] < pack[i-cost]+val)
				pack[i] = pack[i-cost]+val;
	}
	void lim(int cost,int val,int t)
	{
		int now=1;
		while(t>=now)
		{
			zero(cost*now,val*now);
			t-=now;
			now<<=1;
		}
		if(t)
			zero(cost*t,val*t);
	}
	int out()
	{
		return pack[n];
	}
	
}pack[3];

int cost[M],val[M],pbag[3];
int store[3][M],len[3],n,ma;

void dfs(int now)
{
	if(now<0)
	{
		FR(i,n)
			pack[i].init(pbag[i]);
		FR(i,n)
			FR(j,len[i])
				pack[i].zero(cost[ store[i][j] ],val[ store[i][j]] );
		int now=0;
		FR(i,n)
			now+=pack[i].out();
		if(now > ma)
			ma = now;
		return ;
	}
	FR(i,n)
	{
		store[i][ len[i]++ ]= now ;
		dfs(now-1);
		len[i]--;
	}	
}

int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	while(cin >> n)
	{
		FR(i,n)
		{
			cin >> pbag[i];
			len[i]=0;
		}
		
		int t;
		cin >> t;
		FR(i,t)
			cin >> cost[i] >> val[i];
			
		ma=0;
		dfs(t-1);
		
		cout << ma << endl ;
		
	};
}
	return 0;
};
/*
start 71 min
end 80 min
i give up beacuse i don;t know how to deal with more backpack
*/

#include<bits/stdc++.h>
#define ll long long 
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

#define M 10010

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
	
}pack;


int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		int x[n],y[n];
		FR(i,n)
			cin >> x[i] >> y[i];
		int p;
		cin >> p;
		pack.init(p);
		FR(i,n)
			pack.zero(x[i],y[i]);
		cout << pack.out() << endl ;
	};
}
	return 0;
};
/*
10min quick
*/

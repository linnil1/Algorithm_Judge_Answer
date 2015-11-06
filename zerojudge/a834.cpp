#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=0;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define FORE(i,a,n) for(int i=a;i<=n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ARR(arr,n) ll arr[n+2];for(int i=0,s=n;i<s;++i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define QI std::queue<int>
#define VI std::vector<ll>
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>

#define MP std::pair<int,int>
using namespace std;



VI atk,def;

ll tozero(ll* have,int n,int m)
{
	if(n>m)
		return 0;
	
	ll sum=0;
	ARR(arr,m)
		sum+=arr[i]=have[i];
	int j=0;
	FR(i,def.size())
	{
		while(j<m && arr[j]<=def[i])
			++j;
		if(j>=m)
			return 0;
		sum-=arr[j];
		arr[j++]=0;
	}
	int now=0;
	FR(i,m)
		if(arr[i])
			arr[now++]=arr[i];
	
	--now;
	BFR(i,atk.size())
		if(atk[i]>arr[now--])
			return 0;
		else
			sum -= atk[i];	
	
	return sum;	
}
ll tomin(ll* have,int n,int m)
{
	ll sum=0;
	for(int i=0;i<atk.size() && m && atk[i]<have[m-1];++i)
		sum += have[--m]-atk[i];
	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(cin >> n >> m)
	{
		atk.clear();def.clear();
		FR(i,n)
		{
			string s;ll k;
			cin >> s>> k ;
			if(s=="ATK")
				atk.pb(k);
			else
				def.pb(k);
		}
		sort(ALL(atk));
		sort(ALL(def));
		
		ARR(have,m)
			cin >>have[i];
		sort(have,have+m);
		
		cout << max(tozero(have,n,m) , tomin(have,n,m)) << endl;
		
	};
}
	return 0;
};
/*
1hr slow is not useful


2 3
ATK 2000
DEF 1700
2500
2500 
2500

3 4
ATK 10
ATK 100
ATK 1000
1
11
101
1001        
*/


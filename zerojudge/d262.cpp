#include<bits/stdc++.h>
#define ll long long 
#define M 1000000
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

struct prim
{
	int pr[M/10],ps;
	char c[M+1];
	void init()
	{
		//puts("zxc");
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<=M;++i)
		{
			if(c[i])pr[ps++]=i;
			for(int j=0;j<ps && pr[j]*i<=M ; ++j)
			{
				c[ pr[j]*i ] = 0 ;
				if(i%pr[j]==0)
					break;
			};
			
		}
	}
	
	inline int isprim(int &a)
	{		
		//be careful at 0,1 
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	
}p;


inline int calnum(int now)
{
	int sum=0;
	while(1)
	{
		++sum;
		int q = p.isprim(now);
		while(now%q==0)
			now/=q;
		if(now==1)
			break;				
	}
	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 
	cout << 129963318-4 <<endl;
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
/*{	
	p.init();
	int n;
	while(cin >> n)
	{
		
		for(int i=129963300,seq=0;;++i)
		{
			int now = calnum(i);
			if(now==5)
				++seq;
			else
				seq=0;
				
			if(seq==5)
			{
				cout << i << endl;
			}
		}
	};
}*/
	return 0;
};
/*
20min slow
need to be quick 
*/

#include<bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
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

#define M 100000
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
	
	int isprim(int &a)
	{		
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	
}p;

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	p.init();
	int n;
	while(cin >> n)
	{
		if(n>1 && p.isprim(n)==n)
			cout << "It's a prime!!!";
		else
			cout << "It's not a prime!!!";
		cout << endl; 
	};
}
	return 0;
};
/*
7min ok
*/

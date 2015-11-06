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
using std::sort;using std::endl;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MANN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) ll arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;
ll a[500][500],b[500][500],c[500][500];

int gorand(int n,int &ok)
{
	if(!ok)
		return 0;
	ARR(r,n)r[i]=rand();
	ll tmp1[n],tmp2[n],tmp3[n];
	
	FR(i,n)
	{		
		ll t=0;
		FR(j,n)
			t = (t + r[j]*c[i][j]%MOD)%MOD;	
		tmp1[i] = t;
	};
	FR(i,n)
	{		
		ll t=0;
		FR(j,n)
			t = (t + r[j]*b[i][j]%MOD)%MOD;	
		tmp2[i]=t;
	};
	FR(i,n)
	{		
		ll t=0;
		FR(j,n)
			t = (t + a[i][j]*tmp2[j]%MOD)%MOD;	
		tmp3[i] = t ;
	};
	FR(i,n)
		if(tmp1[i]!=tmp3[i])
			return ok=0;
	return 1;
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(~scanf("%d",&n))
	{
		
		FR(i,n)
			FR(j,n)
			{
			
				scanf("%lld",a[i]+j);
				a[i][j]=(a[i][j]%MOD+MOD)%MOD;
			}
		FR(i,n)
			FR(j,n)
			{			
				scanf("%lld",b[i]+j);
				b[i][j]=(b[i][j]%MOD+MOD)%MOD;
			}
		FR(i,n)
			FR(j,n)
			{			
				scanf("%lld",c[i]+j);
				c[i][j]=(c[i][j]%MOD+MOD)%MOD;
			}
		
		srand(n/2+a[0][0]);
		int ok=1;
		gorand(n,ok);		
		
		if( ok )
			puts("YES");
		else
			puts("NO");
	};
}
	return 0;
};
/*
learn !!
it is the random solution




*/

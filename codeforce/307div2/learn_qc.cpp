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
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

int ok(int *arr,int n,int stu,ll t)
{
	int now=0;
	ll box=0;
	FR(i,stu)
	{		
		while(box==0)
		{
			if(now==n)
				return 1;
			box = arr[now++];
		}		
		if(t<=now)
			return 0;					
		ll ener = t-now;
		while(ener)
		{
			ll min = MIN(box,ener);
			box -=min;
			ener-=min;
			while(now<n && box==0 && ener)
			{
				--ener;
				box = arr[now++];
			}
			if(now==n && box==0)
				return 1;
		};
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,stu;
	while(cin >> n >> stu)
	{
		ll sum=0;
		ARR(p,n)
		{
			cin >> p[i];
			sum+=p[i];
		}
		while(n && p[n-1]==0)
			--n;
		ll min=0,max=sum+n*stu;
		while(min+1<max)
		{
			ll mid=(min+max)>>1;
			if(ok(p,n,stu,mid))
				max = mid ;
			else
				min = mid;
		}
		cout << max << endl;
	};
}
	return 0;
};
/*






*/

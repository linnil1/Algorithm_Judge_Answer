#include<bits/stdc++.h>
#define ll long long 
#define M 2001
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
struct xy
{
	int x,y;
};

int gcd(int a,int b){return b ? gcd(b,a%b) : a;};
MP modi(MP &a)
{
	if(a.ft==0)
		return mp(0,1);
	if(a.sd==0)
		return mp(1,0);
	if(a.ft<0)
	{
		a.ft=-a.ft;
		a.sd=-a.sd;
	}
	int g = gcd( a.ft ,abs(a.sd));
	return mp(a.ft/g , a.sd/g);
}


ll C(ll a,int b=3)
{
	if(a<3)
		return 0;
	return a*(a-1)*(a-2)/6;
}

ll gosum(VI &v)
{
	if(!v.size())
		return 0;
	sort(ALL(v));
	
	int now=-1,w=0;	
	ll sum=0;	
	FR(i,v.size())
		if(v[i]!=now)
		{
			if(now!=-1)
			{
				sum += C(now)*w/now;
			}
			now=v[i],w=1;
		}	
		else
			++w;
	if(now!=-1)
	{
		sum += C(now)*w/now;
	}
	//cout << sum <<"!";
	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		
		xy tri[n];
		VI v;
		FR(i,n)
		{
			cin >> tri[i].x >> tri[i].y;
		}
		if(n<=2)
		{
			cout << 0 << endl;
			continue;
		}
		MP s[n];
		
		FR(i,n)
		{
			int now=0;
			int &x = tri[i].x,&y=tri[i].y;
			FR(j,n)
				if(i!=j)
				{
					MP t( tri[j].x-x  , tri[j].y-y );
					s[now++] = modi(t);
				}
			std::sort(s,s+now);
			
			int sum=1;
			FOR(j,1,now)
				if(s[j]==s[j-1])
					++sum;
				else
				{
					if(sum>1)
						v.pb(sum+1);
					sum=1;
				}
			if(sum>1)
				v.pb(sum+1);
		}
		
		cout << C(n)-gosum(v) << endl;
	};
}
	return 0;
};
/*
3
0 0
1 1
2 0


4
0 0
1 1
2 0
2 2


1
1 1



*/

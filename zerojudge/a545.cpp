#include<bits/stdc++.h>
#define ll long long 
#define M 1010
#define MOD 100000007 
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
using std::sort;using std::endl;
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

ll stu[M][M];

inline ll inv(ll a,ll p){return a==1 ? 1 : inv(p%a,p)*(p-p/a)%MOD;}

template <class T>
inline int IN(T &a)
{
	static char c,neg;
	while((c=getchar())<'-')
		if(c== EOF)
			return EOF;
			
	a = (neg= c=='-') ? 0 : c-'0' ;
	while((c=getchar())>='0')
		a = a*10+c-'0';
	a = neg?-a:a;
	return 1;
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(~scanf("%d%d",&n,&m) && n && m)
	{
		ll sum=1;
		FR(i,n)
			FR(j,m)
				IN(stu[i][j]),
				sum = stu[i][j]%MOD * sum %MOD;
		
		int t;
		scanf("%d",&t);
		while(t--)
		{
			int x,y;
			IN(x);IN(y);
			printf("%lld\n",inv(stu[x-1][y-1],MOD) *sum%MOD);
		}
		
	};
}
	return 0;
};
/*

2:40
3:00
20min late but know the io be greater










*/

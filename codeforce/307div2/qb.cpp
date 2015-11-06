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

int findmin(int *c,int *ca)
{
	int min = INT_MAX;
	for(int i='a';i<='z';++i)
		if(ca[i] && c[i]/ca[i]<min)
			min = c[i]/ca[i];
	return min;				
}
int modi(int *c,int *ca,int v)
{
	for(int i='a';i<='z';++i)
		if(ca[i] )
			c[i] -= v*ca[i];		
}

MP findmax(int *c,int *ca,int *cb)
{
	MP ans;
	int sum=0;
	for(int i=findmin(c,ca);i>=0;--i)
	{
		modi(c,ca,i);
		int now = findmin(c,cb) ;
		if( now+i > sum)
		{
			sum = now+i;
			ans = mp(i,now);
		}
		modi(c,ca,-i);
		
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	string a,b,c;
	while(cin >> a >> b >> c)
	{
		
		int ch[500],ca[500],cb[500];
		for(int i='a';i<='z';++i)
			ch[i]=ca[i]=cb[i]=0;
		FR(i,a.size())
			++ch [ a[i] ];
		FR(i,b.size())
			++ca [ b[i] ];
		FR(i,c.size())
			++cb [ c[i] ];
		
		MP ans = findmax(ch,ca,cb);
		modi(ch,ca,ans.ft);	
		modi(ch,cb,ans.sd);
		FR(i,ans.ft)
			cout << b ;
		FR(i,ans.sd)
			cout << c;
		for(int i='a';i<='z';++i)
			FR(j,ch[i])
				cout << char(i) ;
		cout << endl ;
		
	};
}
	return 0;
};
/*






*/

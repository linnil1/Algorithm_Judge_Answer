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

struct disjointset
{
	static const int MM=100100;
	int s[MM],n,group[MM];
	void init(int _n)
	{
		 n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ,
			group[i] = 1 ;
	};
	
	int find(int a)
	{
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b)
	{
		if(find(a)!=find(b))
		{
			group[find(b)] += group[find(a)];
			s[find(a)] = find(b);			
			return 1;
		}
		else
			return 0;
	}	
	
}s;

void outline(MP *v,int n,int m)
{
	s.init(n);
	ARR(use,m)use[i]=1;		
	
	typedef std::pair<char,int> pci;
	int t;cin >> t;char c[100];
	std::stack<pci> st;
	while(t--)
	{
		int a;
		cin>>c>>a;
		st.push( mp(c[0],a) );
		if(c[0]=='D')
			use[a-1]=0;
	}
	FR(i,m)
		if(use[i])
			s.unin(v[i].ft , v[i].sd);
	
	std::stack<int> ans;
	while(st.size())
	{
		pci now = st.top();st.pop();
		if(now.ft=='D')
			s.unin(v[now.sd-1].ft,v[now.sd-1].sd);
		else
			ans.push( s.group[s.find(now.sd)] );	
	}
	
	while(ans.size())
	{
		cout << ans.top() << endl;
		ans.pop();
	}
	
}
int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(cin >> n >> m)
	{
		MP v[m];
		FR(i,m)
		{
			int x,y;cin >> x >> y ;
			v[i] = mp (x,y);
		}
		
		outline(v,n,m);
		
		
	};
}
	return 0;
};
/*






*/

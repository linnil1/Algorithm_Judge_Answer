#include<bits/stdc++.h>
#define ll long long 
#define M 500010
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

int gap,len;
ll	pls[M],arr[M];
std::map<ll,int> s[M];

inline void tomap(int &g,ll &val,ll &v)
{
	if(s[g][val]>1)
		--s[g][val];
	else
		s[g].erase(val);
	val+=v;
	++s[g][val];
}

void modi(int n)
{
	int l,r;
	ll v;cin >> l >> r >> v;
	--l;--r;
	int lg = l/gap ,rg =r/gap;
	
	if(lg == rg)
		FORE(i,l,r)
			tomap(lg,arr[i],v);
	else
	{
		FORE(i,lg+1,rg-1)
			pls[i]+=v;
		for(int i=MIN(lg*gap+gap,n)-1;i>=l;--i)		
			tomap(lg,arr[i],v);
		for(int i=rg*gap;i<=r;++i)
			tomap(rg,arr[i],v);
	}	
}
int ask(int n)
{
	int k,l=-1,r=n;
	cin >> k ;
	for(int i=0;i<len&&l==-1;++i)
		if(k>=pls[i] && s[i].count(k-pls[i]))
		{
			int lg=i*gap ,rg = MIN(n,lg+gap);
			if(pls[i])
			{
				FOR(j,lg,rg)
					arr[j]+=pls[i];
				s[i] = std::map<ll,int>();
				FOR(j,lg,rg)
					++s[i][arr[j]];
				pls[i]=0;
			}			
			FOR(j,lg,rg)
				if(arr[j]==k)
				{
					l=j;
					break;
				}
		}
	if(l==-1)
		return -1;
	for(int i=len-1;i>=0 && r==n;--i)	
		if(k>=pls[i] && s[i].count(k-pls[i]))
		{
			int lg=i*gap ,rg = MIN(n,lg+gap);
			if(pls[i])
			{
				FOR(j,lg,rg)
					arr[j]+=pls[i];
				s[i] = std::map<ll,int>();
				FOR(j,lg,rg)
					++s[i][arr[j]];
				pls[i]=0;
			}			
			for(int j=rg-1;j>=lg;--j)
				if(arr[j]==k)
				{
					r=j;
					break;
				}
		}	
	return r-l;
	
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
		//init
		FR(i,n)
			cin>>arr[i];		
		gap =(int)sqrt(n);
		len = n/gap + (n%gap>0);
		
		FR(i,len)			
			s[i] = std::map<ll,int>(),//number times
			pls[i]=0;	
		//build
		FR(i,n)
			++s[i/gap][arr[i]];
		//ask
		while(m--)
		{
			int type;cin >> type;
			if(type==1)
				modi(n);
			else//==2
				cout << ask(n) << endl ;
		}
		
		
	};
}
	return 0;
};
/*






*/

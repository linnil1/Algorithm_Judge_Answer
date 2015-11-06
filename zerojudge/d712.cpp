#include<bits/stdc++.h>
#define ll long long 
#define M 1000001
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

int ans[M];

int go(ll i)
{
	if(i>=M)
		return go( i%2? 3*i+1 : i>>1 )+1;
	if(ans[i])
		return ans[i];
	return ans[i] = go( i%2? 3*i+1 : i>>1 )+1 ;
}

void build()
{
	FR(i,M)
		ans[i]=0;
	ans[1]=1;
	FOR(i,2,M)
		go(i);	
}


struct seg
{
	int max;
	seg *l,*r;
	seg(){}
	
	void pull()
	{
		max = std::max( l->max , r->max );
	}
};

seg* build(int l,int r)
{
	seg* now = new seg();
	if(l==r)
	{
		now->max = ans[l];
		return now;
	}
	int mid = (l+r)>>1;
	now->l = build(    l,mid);
	now->r = build(mid+1,  r);
	now->pull();
	return now;		
}
int ask(seg* a,int l,int r,int x,int y)
{
	if(l>y || r<x)
		return -2147483648;
	if(x<=l && r<=y)
		return a->max ;
		
	int mid = (l+r)>>1;
	return std::max( ask(a->l,    l,mid,x,y) , 
				     ask(a->r,mid+1,  r,x,y) );
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 
	build();
	seg *root = build(1,M-1);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int oa,ob,a,b;
	while(cin >> oa >> ob )
	{
		a=oa;b=ob;
		if(a>b)swap(a,b);
		cout << oa<<" "<<ob<<" "<<ask(root,1,M-1,a,b) << endl ;
	};
}
	return 0;
};
/*
where to +1
and a>b problem





*/

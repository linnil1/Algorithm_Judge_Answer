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
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;
struct seg
{
	int min;
	seg *l,*r;
	seg():min(INT_MAX){}
	void push()
	{
		if(min==INT_MAX)
			return ;
		if(min < l->min)
			l->min = min ;
		if(min < r->min)
			r->min = min ;
		min = INT_MAX;
	}
};

struct {
	int o,n;//<=n
	seg *root;
	void init(int _o , int _n){
		n = _n;
		o = _o;
		root = build(o,n);
	}
	int fix(int x,int y,int v){
		return fix(root,o,n,x,y,v);
	}
	int ask(int i){
		return ask(root,o,n,i);
	}
	
	int ori[M];
	seg* build(int l,int r)//l<=x<=r
	{
		seg* now = new seg();
		if(l==r)
		{
			return now;
		}
		int mid = (l+r)>>1;
		now->l = build(    l,mid);
		now->r = build(mid+1,  r);
		return now;		
	}
	int fix(seg* a,int l,int r,int &x,int &y,int &v)
	{
		if(l>y || r<x)
			return 0;
		if(x<=l && r<=y)
			return a->min = MIN(a->min , v) ;
		a->push();
		int mid = (l+r)>>1;
		fix(a->l,    l,mid,x,y,v) ;
		fix(a->r,mid+1,  r,x,y,v) ;
	}
	
	int ask(seg *a,int l,int r,int &i)
	{
		if(l==r)		
			return a->min;
		
		a->push();
		int mid = (l+r)>>1;
		if(mid >=i) 
			return ask(a->l,    l,mid,i);
		else
			return ask(a->r,mid+1,  r,i);
	}	
}segt;



struct package
{
	ll pack[M];
	int n;
	void init(int _n)
	{
		n = _n;
		for(int i=0;i<=n;++i)
			pack[i]=0;
	}
	void zero(int cost,int val)
	{
		for(int i=n-cost;i>=0;--i)
			if(pack[i+cost] < pack[i]+val )
				pack[i+cost] = pack[i]+val;
	}
	void mult(int cost,int val)
	{
		for(int i=cost;i<=n;++i)
			if(pack[i] < pack[i-cost]+val)
				pack[i] = pack[i-cost]+val;
	}
	void lim(int cost,int val,int t)
	{
		int now=1;
		while(t>=now)
		{
			zero(cost*now,val*now);
			t-=now;
			now<<=1;
		}
		if(t)
			zero(cost*t,val*t);
	}
	ll out()
	{
		return pack[n];
	}
	
}pack;

struct xy{
	int v,c;
};

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,money,m;
	while(cin >> n >> money>> m){
		xy arr[n+2];
		ll sum=0;
		FRE(i,n){
			cin >>arr[i].v;
			sum += arr[i].v;
		}
			
		segt.init(1,n);
		FR(i,m){
			int x,y,v;
			cin >> x >> y >> v;
			segt . fix(x,y,v);			
		}
		FRE(i,n)
			arr[i].c = segt.ask(i);
		pack.init(money);
		FRE(i,n)
			if(arr[i].v<0)
			{
				pack.zero(arr[i].c,-arr[i].v);
			}
		
			
		cout << sum+pack.out() << endl;
	};
}
	return 0;
};
/*






*/

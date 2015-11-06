#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 12345
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
	ll sum;
	seg *l,*r;
	seg():sum(0){}
	
	void pull()
	{
		sum = ( l->sum + r->sum ) %MOD;
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
	int ask(int x,int y){
		return ask(root,o,n,x,y);
	}
	void fix(int i,ll v){
		return fix(root,o,n,i,v);
	}
	seg* build(int l,int r)//l<=x<=r
	{
		seg* now = new seg();
		if(l==r)
		{
			now->sum = 0;
			return now;
		}
		int mid = (l+r)>>1;
		now->l = build(    l,mid);
		now->r = build(mid+1,  r);
		//now->pull();
		return now;		
	}
	ll ask(seg* a,int l,int r,int &x,int &y)
	{
		if(l>y || r<x)
			return 0;
		if(x<=l && r<=y)
			return a->sum ;
			
		int mid = (l+r)>>1;
		return  (ask(a->l,    l,mid,x,y) + 
				ask(a->r,mid+1,  r,x,y))%MOD ;
	}
	
	void fix(seg *a,int l,int r,int &i,ll &v)
	{
		if(l==r)
		{
			//ori[l]+=v;
			a->sum=(a->sum+v)%MOD;
			return ;
		}
		int mid = (l+r)>>1;
		if(mid >=i) 
			fix(a->l,    l,mid,i,v);
		else
			fix(a->r,mid+1,  r,i,v);
		a->pull();	
	}	
}up,down;

int scat(int *arr,int n){
	std::map<int,int> m ;
	FR(i,n)
		m[arr[i]];
	int len=0;
	for(auto &i:m)
		i.sd=len++;
	FR(i,n)
		arr[i] = m[arr[i]];	
	return m.rbegin()->sd ;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		int arr[1600];		
		FR(i,n)
			scanf("%d",arr+i);
		int mm = scat(arr,n);		
		up.init(0,mm);
		down.init(0,mm);
		int coun[mm+1];
		FR(i,mm+1)
			coun[i]=0;
		FR(i,n){
			int &x =arr[i];
			coun[x]++;
			ll cu = down.ask(x+1,down.n),
				cd = up.ask(0,x-1);
			
			up.fix(x,cu+1);
			down.fix(x,cd+1);			
		}
		
		ll sum = up.ask(0,up.n)+down.ask(0,down.n) ;
		//cout << sum << endl;
		FR(i,n)
			sum -= ( n-i-1 - --coun[arr[i]])%MOD;
		sum = (sum+MOD*MOD-2*n)%MOD;
		printf("%lld\n",sum);
		
		
	};
}
	return 0;
};
/*






*/

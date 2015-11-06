#include<bits/stdc++.h>
#define ll long long 
#define M 100100
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
#define SC(a) scanf("%d",&a);
#define PR(a) printf("%d ",a);
#define VMP std::vector<MP>
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
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

struct seg{
	int max;
	seg *l,*r;
	seg():max(0){}
	void pull(){
		max = MAX(l->max , r->max);
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
	void fix(int i,int v){
		return fix(root,o,n,i,v);
	}
	
	seg* build(int l,int r){//l<=x<=r
		seg* now = new seg();
		if(l==r){
			return now;
		}
		int mid = (l+r)>>1;
		now->l = build(    l,mid);
		now->r = build(mid+1,  r);
		//now->pull();
		return now;		
	}
	int ask(seg* a,int l,int r,int &x,int &y){
		if(l>y || r<x)
			return -2147483648;
		if(x<=l && r<=y)
			return a->max ;
		int mid = (l+r)>>1;
		return std::max( ask(a->l,    l,mid,x,y) , 
					     ask(a->r,mid+1,  r,x,y) );
	}
	
	void fix(seg *a,int l,int r,int &i,int &v){
		if(l==r){
			//ori[l]+=v;
			a->max=v;
			return ;
		}
		int mid = (l+r)>>1;
		if(mid >=i) 
			fix(a->l,    l,mid,i,v);
		else
			fix(a->r,mid+1,  r,i,v);
		a->pull();	
	}	
}tree;



int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n)){		
		VMP v;
		FRE(i,n){
			int x;scanf("%d",&x);
			if( x<=i){
				v.pb( mp(i-x,x));
			}
		}
		
		sort( ALL(v) );
		/*for(MP &i:v)
			printf("%d %d\n",i.ft,i.sd);
		puts("");*/
		tree.init( 0,n);
		
		for(MP &i : v){
			tree.fix ( i.sd , tree.ask(0,i.sd-1)+1) ;
		}
		printf("%d\n",tree.ask(0,n));
		
		
	};

	return 0;
};
/*






*/

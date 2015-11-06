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
	int size,cancov;
	ll sum, m,p,cov;
	seg *l,*r;
	seg():p(0),m(1),sum(0),cov(0),cancov(0),size(1){}
	void push(){
		if(cancov){
			l->cancov= r->cancov = 1;
			l->cov = r->cov = cov;
			p=0;m=1;
			cancov = cov=0;
			return ;
		}
		//val = (m*val%MOD + p)%MOD;	
		if(l->cancov)
			l->cov = (l->cov *m %MOD + p )%MOD;
		else{			
			l->p = ( l->p * m %MOD + p)%MOD;
			l->m = l->m* m %MOD;
		}
		if(r->cancov)
			r->cov = (r->cov *m %MOD + p )%MOD;
		else{			
			r->p = ( r->p * m %MOD + p)%MOD;
			r->m = r->m* m %MOD;
		}
		p=0;m=1;
	}
	void pull()
	{
		size = l->size + r->size ; 
		
		sum =0 ;
		if(l->cancov)
			sum += l->cov * l->size % MOD;
		else
			sum += (l->sum * l->m % MOD + l->p * l->size%MOD )%MOD;	
		if(r->cancov)
			sum += r->cov * r->size% MOD;
		else
			sum += (r->sum * r->m % MOD + r->p * r->size%MOD )%MOD;
		//cout << sum << " ";	
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
	ll ask(int x,int y){return ask(root,o,n,x,y);}
	int add  (int x,int y,int v){return   add(root,o,n,x,y,v);}
	int mult (int x,int y,int v){return  mult(root,o,n,x,y,v);}
	int cover(int x,int y,int v){return cover(root,o,n,x,y,v);}
	int ori[M];
	seg* build(int l,int r)//l<=x<=r
	{
		seg* now = new seg();
		if(l==r)
		{
			now->cancov = 1;
			now->cov = ori[l];
			return now;
		}
		int mid = (l+r)>>1;
		now->l = build(    l,mid);
		now->r = build(mid+1,  r);
		now->pull();
		return now;		
	}
	ll ask(seg* a,int l,int r,int &x,int &y)
	{
		if(l>y || r<x)
			return 0;
		
		if(x<=l && r<=y)
			if(a->cancov)
				return a->cov*a->size% MOD;
			else
				return ( a->sum * a->m %MOD + 
				    a->p * a->size%MOD )%MOD;
			
		a->push();			
		int mid = (l+r)>>1;		
		ll ans = (ask(a->l,    l,mid,x,y) + 
				  ask(a->r,mid+1,  r,x,y) )%MOD;
		a->pull();
		return ans;
	}
	
	int add(seg* a,int l,int r,int &x,int &y,int &v){
		if(l>y || r<x)
			return 0;
		
		if(x<=l && r<=y)
			if(a->cancov)
				return a->cov = (v + a->cov)%MOD;
			else
				return a->p = ( v + a->p)%MOD;
			
		a->push();			
		int mid = (l+r)>>1;		
		add(a->l,    l,mid,x,y,v) ;
		add(a->r,mid+1,  r,x,y,v) ;
		a->pull();
	}
	int mult(seg* a,int l,int r,int &x,int &y,int &v){
		if(l>y || r<x)
			return 0;
		
		if(x<=l && r<=y)
			if(a->cancov)
				return a->cov = a->cov *v %MOD;
			else{
				a->m = a->m *v %MOD;
				a->p = a->p *v %MOD;
				return 0;
			}
			
		a->push();			
		int mid = (l+r)>>1;		
		mult(a->l,    l,mid,x,y,v) ;
		mult(a->r,mid+1,  r,x,y,v) ;
		a->pull();
	}
	int cover(seg* a,int l,int r,int &x,int &y,int &v){
		if(l>y || r<x)
			return 0;
		
		if(x<=l && r<=y){
			a->cancov = 1;
			return a->cov = v;
		}
			
		a->push();			
		int mid = (l+r)>>1;		
		cover(a->l,    l,mid,x,y,v) ;
		cover(a->r,mid+1,  r,x,y,v) ;
		a->pull();
	}
	void postorder(seg *a){
		if(!a)return ;
		postorder(a->l);
		postorder(a->r);
		cout  << a->sum <<" " <<a->m<<" "  << a->p <<" " 
			<< a->cov << endl;
		
	}
}tree;



int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(cin >> n >> m){
		FRE(i,n)
			cin >> tree.ori[i] ;
		tree.init(1,n);
		//tree.postorder(tree.root);
		while(m--){
			int type,x,y,v;
			cin >> type >> x >> y ;
			if(type!=4) cin >> v;
			if(x>y){
				if(type==4)
					cout << "0\n";
				continue;
			}
			switch(type){
				case 1:tree.add(x,y,v);break;
				case 2:tree.mult(x,y,v);break;
				case 3:tree.cover(x,y,v);break;
				case 4: cout << tree.ask(x,y) << endl;break;
			}
			//tree.postorder(tree.root);
		}
	};
}
	return 0;
};
/*

be careful to mod




*/

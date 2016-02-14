char need_time=0;
#define M 100010
#define MOD 1000000007
#include<bits/stdc++.h>
#define ll long long 
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
#define ft first
#define sd second
#define pb push_back
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define VMP std::vector<MP>
#define MP std::pair<int,int>
#define IN(a) scanf("%d",&a)
#define INN(a,b) scanf("%d%d",&a,&b)

//using namespace std;

const int MM = 35100;

struct seg{
	ll sum;
	seg *l,*r;
	
	seg():sum(0){}
	
	void pull(){
		sum = l->sum + r->sum ;
	}
}fornew[MM*20],*fornews;

struct segment_tree{
	int o,n;//<=n
	seg *root;
	
	void init(int _o , int _n){
		n = _n;
		o = _o;
		fornews =fornew ;
		root = build(o,n);
	}
	
	int ask(int x,int y){
		if(x>y)std::swap(x,y);
		return ask(root,o,n,x,y);
	}
	
	void fix(int i,int v){
		return fix(root,o,n,i,v);
	}
	
	int ori[MM];
	seg* build(int l,int r){//l<=x<=r
		seg* now = new (fornews++) seg();
		if(l==r){
			now->sum = ori[l];
			return now;
		}
		int mid = (l+r)>>1;
		now->l = build(    l,mid);
		now->r = build(mid+1,  r);
		now->pull();
		return now;		
	}
	
	int ask(seg* a,int l,int r,int &x,int &y){
		if(l>y || r<x)
			return 0;
		if(x<=l && r<=y)
			return a->sum ;
		int mid = (l+r)>>1;
		return ask(a->l,    l,mid,x,y)+ask(a->r,mid+1,  r,x,y);
	}
	
	void fix(seg *a,int l,int r,int &i,int &v){
		if(l==r){
			//ori[l]+=v;
			a->sum+=v;
			return ;
		}
		int mid = (l+r)>>1;
		if(mid >=i) 
			fix(a->l,    l,mid,i,v);
		else
			fix(a->r,mid+1,  r,i,v);
		a->pull();	
	}	

};

struct hlt{
	int val;
	int fa,dep;
	int top,ti;
};

struct heavy_ligt_decomposition{
	int n;
	hlt v[MM];
	std::vector<int> V[MM];

	void init(int _n){
		n = _n ;
		for(int i=0;i<n;++i)
			v[i].val=0,
			V[i] = std::vector<int>();	
	};

	void add(){
		int a,b;
		scanf("%d%d",&a,&b);
		V[a].pb(b);
	}

	// set max_son
	int time,mson[MM];
	void setmson(int i){
		if(i==-1)
			return ;
		for(int j=i; j==i || j!=-1 ;j=mson[j]){
			v[j].ti=time++;
			v[j].top = i;
		}
	}

	void decompose(){
		int st[MM],sto=0;
		v[0].dep=v[0].fa=0;
		st[sto++] = 0;
	
		// set dep & fa
		for(int j=0;j<sto;++j){
			int &now = st[j];
			for( int &i:V[now])
				if( i!= v[now].fa){
					v[i].fa = now;
					v[i].dep = v[now].dep+1;
					st[sto++] = i ;
				}
		}
	
		// set size, mson
		int size[MM],max[MM];
		time=0;
		for(int i=0;i<n;++i)
			size[i]= 1,
			mson[i]=-1,
			max[i] = 0;

		for(int j=sto-1;j>0;--j){
			int &now=st[j],&fa = v[now].fa;
			   size[fa]+= size[now];
			if( max[fa] < size[now]){
				max[fa] = size[now];
				setmson(mson[fa]);
				mson[fa] = now ;
			}
			else
				setmson(now);
		}
		setmson(0);

	}
	
	segment_tree segt;
	void gohld(int n,int m){
		init(n);
		for(int i=0;i<m;++i)
			add();
		decompose();
//		for(int i=0;i<n;++i)printf("%d:%d %d %d\n",i,mson[i],v[i].fa,v[i].top);
		
		for(int i=0;i<n;++i)
			segt.ori[v[i].ti] = v[i].val;
		segt.init(0,n-1);

	}

	int cal(int a,int b){
		int sum=0;
		while( v[a].top != v[b].top){
			if( v[a].dep < v[b].dep )
				std::swap(a,b);
			int t = v[a].top;
			// here
			sum += segt.ask(v[a].ti,v[t].ti);
			// done
			a = v[t].fa;
		}

		//here 
		sum +=  segt.ask(v[a].ti,v[b].ti);
		//done
		return sum;
	}

}hldtree;

int main(){
//	std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	int n;
	while(~scanf("%d",&n)){
		hldtree.gohld(n,n-1);

		int m;IN(m);
		FR(i,m){
			int a,b;
			INN(a,b);
			hldtree.segt.fix(hldtree.v[a].ti,b);
			printf("%d\n",hldtree.cal(0,a));
		}
		
		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/
/*
	void dfs(int a){ // get size and max_son
		int m=0;
		for(int &i:V[a])
			if( i!= v[a].fa){
				v[i].fa = a;
				v[i].dep = v[a].dep+1 ;
				dfs(i);
				if(v[i].size > m ){
					m = v[i].size;
					v[a].mson = i;
				}
				v[a].size += v[i].size;
			}
	}
*/
/*
	int time;
	void makelink(int fr,int num){
		v[fr].top = num ;
		v[fr].ti = time++;
		if(v[fr].mson==-1)
			return ;
		makelink(v[fr].mson,num);
		for(int &i:V[fr])
			if(i!=v[fr].fa && i!=v[fr].mson )
				makelink(i,i);
	}
*/

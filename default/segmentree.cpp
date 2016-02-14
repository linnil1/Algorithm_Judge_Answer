const int MM = 1000100;
struct seg{
	int max;
	ll sum,add;
	seg *l,*r;
	
	seg():max(0),sum(0),add(0){}
	void push(){
		if(add){
			l->add +=add;
			r->add +=add;
			add=0;
		}
	}
	
	void pull(){
		max = std::max( l->max , r->max );
		sum = l->sum + r->sum ;
	}
}for_alloc[MM*30],*for_allocs;

struct {
	int o,n;//<=n
	seg *root;
	
	void init(int _o , int _n){
		n = _n;
		o = _o;
		for_allocs = for_alloc;
		root = build(o,n);
	}
	
	int ask(int x,int y){
		return ask(root,o,n,x,y);
	}
	
	void fix(int i,int v){
		return fix(root,o,n,i,v);
	}
	
	int ori[MM];
	seg* build(int l,int r){//l<=x<=r
		seg* now = new (for_allocs++)seg();
		if(l==r){
			now->max = ori[l];
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
		a->push();
		int mid = (l+r)>>1;
		return std::max( ask(a->l,    l,mid,x,y) , 
					     ask(a->r,mid+1,  r,x,y) );
	}
	
	void fix(seg *a,int l,int r,int &i,int &v){
		if(l==r){
			//ori[l]+=v;
			a->max+=v;
			return ;
		}
		a->push();
		int mid = (l+r)>>1;
		if(mid >=i) 
			fix(a->l,    l,mid,i,v);
		else
			fix(a->r,mid+1,  r,i,v);
		a->pull();	
	}	
}tree;



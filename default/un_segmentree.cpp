struct seg{
	int size;
	ll sum,add,max;
	seg *l,*r;
	
	seg():size(1),max(0),sum(0),add(0){}
	void push(){
		if(add){
			l->add +=add;
			r->add +=add;
			sum += add*size;
			max += add;
			add=0;
		}
	}
	
	void pull(){
		max = std::max( l->max+ l->size*l->add , r->max+l->size*l->add );
		sum = l->sum + r->sum + l->size*l->add + r->size*r->add ;
	}
};

struct {
	const static int MM = 1000100;
	int o,n;//<=n
	seg *root;
	
	void init(int _o , int _n){
		n = _n;
		o = _o;
		root = build(o,n);
	}
	
	int ask(int x,int y){
		return askran(root,o,n,x,y);
	}
	
	void fix(int i,int v){
		return fixone(root,o,n,i,v);
	}
	
	int ori[MM];
	seg *stupid = new seg();
	seg* build(int l,int r){//l<=x<=r
		seg* now = new seg();
		if(l==r){
			now->max = ori[l];
			now->sum = ori[l];
			now->l=now->r= stupid;
			return now;
		}
		int mid = (l+r)>>1;
		now->l = build(    l,mid);
		now->r = build(mid+1,  r);
		now->size = now->l->size + now->r->size;
		now->pull();
		return now;		
	}
	
	int askone(seg* a,int l,int r,int &x,int &y){
		if(l>y || r<x)
			return -2147483648;
		a->push();
		if(x<=l && r<=y)
			return a->max ;
		int mid = (l+r)>>1;
		return std::max( askone(a->l,    l,mid,x,y) , 
					     askone(a->r,mid+1,  r,x,y) );
	}
	
	int askran(seg* a,int l,int r,int &x,int &y){
		if(l>y || r<x)
			return 0;
		a->push();
		if(x<=l && r<=y)
			return a->sum ;
		int mid = (l+r)>>1;
		return askran(a->l,    l,mid,x,y) + 
		   	   askran(a->r,mid+1,  r,x,y);
	}

	void fixone(seg *a,int l,int r,int &i,int &v){
		a->push();
		if(l==r){
			//ori[l]+=v;
			a->max+=v;
			a->sum+=v;
			return ;
		}
		int mid = (l+r)>>1;
		if(mid >=i) 
			fixone(a->l,    l,mid,i,v);
		else
			fixone(a->r,mid+1,  r,i,v);
		a->pull();	
	}	

	void fixran(seg *a,int l,int r,int x,int y,int &v){
		if(y<l || r<x)
			return ;
		a->push();
		if(l<=x && y<=r){
			a->add=v;
			return ;
		}
		int mid = (l+r)>>1;
		fixran(a->l,    l,mid,x,y,v);
		fixran(a->r,mid+1,  r,x,y,v);
		a->pull();	
	}	
}tree;



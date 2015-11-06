#include<bits/stdc++.h>
#define lld long long int

#define M 10000

struct treap
{
	treap *l,*r;
	int pri,val;
	int size,max;
	lld sum;
	treap(){};
	treap(int _val):l(NULL),r(NULL),pri(rand()),val(_val),
					size(1),max(_val),sum(_val){}
	
};

int size(treap *a){return a ? a->size : 0 ;} 
int max (treap *a){return a ? a->max  : 0 ;} 
lld sum (treap *a){return a ? a->sum  : 0 ;} 

void pull(treap *a)
{
	a->size = size(a->r) + size(a->l) + 1; 
	a->max  = std::max ( std::max ( max (a->r) , max (a->l) ) , a->val );
	a->sum  = sum(a->r) + sum(a->l) + a->val; 
}

treap* merge (treap* a,treap* b)
{
	if(!a || !b) return a? a:b ;
	else if ( a->pri > b->pri)
	{
		a->r = merge( a->r , b);
		pull(a);
		return a;
	}
	else
	{
		b->l = merge (a , b->l);
		pull(b);
		return b;
	}
}

void split (treap* t , int key ,treap* &a,treap*& b)
{
	if(!t)a=b=NULL ; 
	else if(size(t->l) < key )
	{
		a = t ;
		split(t->r , key - 1 - size(t->l) , a->r , b);
		pull(a);
	}	
	else
	{
		b = t ;
		split(t->l , key , a , b->l );
		pull(b);
	}
}
treap *root;
//srand(time(NULL));
//root = NULL ;

void ask()
{
	int l,r;
	scanf("%d%d",&l,&r);
	treap *a=NULL,*b=NULL,*c=NULL;
	split(root, l-1 ,a,b);
	split(b, r-l+1 ,b,c);
	printf("%lld\n",sum(b));
	root = merge( a, merge(b,c) );
}

void back(treap *a,int &m)
{
	if(!a || max(a) < m)
		return ;
	//if(a->val >= m)
	a->val %= m ;
	back(a->l,m);
	back(a->r,m);	
	pull(a);
}
void gomod()
{
	int l,r,m;
	scanf("%d%d%d",&l,&r,&m);
	treap *a=NULL,*b=NULL,*c=NULL;
	split(root, l-1 ,a,b);
	split(b, r-l+1 ,b,c);
	
	back(b,m);	
	
	root = merge( a, merge(b,c) );
}

void chan()
{
	int n,v;
	scanf("%d%d",&n,&v);
	treap *a=NULL,*b=NULL,*c=NULL;
	split(root, n-1 ,a,b);
	split(b, 1 ,b,c);
	
	b->sum = b->val = b->max = v ;
	
	root = merge( a, merge(b,c) );
}
int main()
{
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		root = NULL ;
		while(n--)
		{
			int t;
			scanf("%d",&t);
			root = merge(root , new treap(t) );
		};
		while(m--)
		{
			int t;
			scanf("%d",&t);
			if(t==1)
				ask();
			else if(t==2)
				gomod();
			else if(t==3)
				chan();
		};			
		//printf("%d\n",);
	};
	return 0;
};
/*
*/

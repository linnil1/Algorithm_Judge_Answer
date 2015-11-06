#include<bits/stdc++.h>
//#define lld long long int
struct treap 
{
	static treap men[1000000], *pmen ; 
	treap *l,*r;
	int size,pri;
	int val,max,add;
	treap(){};
	treap(int _val)
		:size(1),pri(rand()),val(_val),max(_val),add(0),
			l(NULL),r(NULL){};
}treap::men[1000000], *treap::pmen = treap::men;

int size(treap *a){ return a ? a->size : 0;}
int max (treap *a){ return a ? a->max  : -100000000 ;}

void pull(treap *a)
{
	a->size = 1 + size(a->r) + size(a->l);
	a->max  = std::max(std::max (max(a->l) , max(a->r) ) , a->val );
};
void push(treap *a)
{
	if(a->add == 0)
		return ;
	if(a->r) a->r->add += a->add;
	if(a->l) a->l->add += a->add;
	a->val += a->add;
	a->add = 0;
};

treap* merge(treap *a,treap *b)
{
	if(!a || !b)return a ? a : b ;
	else if(a->pri > b->pri)
	{
		push(a);
		a->r = merge(a->r , b);
		pull(a);
		return a;
	}
	else
	{
		push(b);
		b->l = merge(a , b->l );
		pull(b);
		return b;
	}
};

void split(treap *t , int key, treap* &a ,treap* &b)
{
	if(!t) a = b = NULL ;
	else if ( size(t->l) < key )
	{
		a = t;
		push(a);
		split(t->r , key - size(t->l) -1 , a->r , b);
		pull(a);
	}
	else
	{
		b = t;
		push(b);
		split(t->l , key , a , b->l);
		pull(b);
	};	
}

treap *root;

void ask()
{
	int a,b;
	scanf("%d%d",&a,&b);
	treap *ta=NULL,*tb=NULL,*tc=NULL;
	
	split(root, a-1, ta, tb);
	split(tb , b-a+1 , tb ,tc );
	printf("%d\n",max(tb));
	
	root= merge(ta , merge(tb,tc));
};

void fix()
{
	int a,b;
	scanf("%d%d",&a,&b);
	treap *ta=NULL,*tb=NULL,*tc=NULL;
	
	split(root, a-1, ta, tb);
	split(tb , 1 , tb ,tc );
	
	tb->val += b;
	tb->max = tb->val ;
	
	root= merge(ta , merge(tb,tc));
		
};

int main()
{
	srand(time(NULL));
	
	int T;
	while(~scanf("%d",&T))
	while(T--)
	{
		root = NULL ;
		int n, m ;
		scanf("%d%d",&n ,&m);
		while(n--)
		{
			int t;
			scanf("%d",&t);			
			root = merge(root , new (treap::pmen++) treap(t));
		};
		while(m--)
		{
			int e;
			scanf("%d",&e);
			if(e==1)
				ask();
			else
				fix();
		};
			
	};
	
	return 0;
};

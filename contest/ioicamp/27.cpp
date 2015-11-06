#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
struct treap 
{
	static treap men[1000000], *pmen ; 
	treap *l,*r;
	int size,pri,val,sum;
	treap(){};
	treap(int _val)
		:size(1),pri(rand()),val(_val),sum(_val),
			l(NULL),r(NULL){};
}treap::men[1000000], *treap::pmen = treap::men;

int size(treap *a){ return a ? a->size : 0 ;}
int sum (treap *a){ return a ? a->sum  : 0 ;}

void pull(treap *a)
{
	a->size = 1 + size(a->r) + size(a->l);
	a->sum  = a->val + sum(a->r) + sum(a->l);
};

treap* merge(treap *a,treap *b)
{
	if(!a || !b)return a ? a : b ;
	else if(a->pri > b->pri)
	{
		a->r = merge(a->r , b);
		pull(a);
		return a;
	}
	else
	{
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
		split(t->r , key - size(t->l) -1 , a->r , b);
		pull(a);
	}
	else
	{
		b = t;
		split(t->l , key , a , b->l);
		pull(b);
	};	
}

treap *root;

void ask()
{
	int a,b;
	scanf("%d%d",&a,&b);
	treap *ta,*tb,*tc;
	
	split(root, a-1, ta, tb);
	split(tb , b-a+1 , tb ,tc );
	printf("%d\n",sum(tb));
	
	root= merge(ta , merge(tb,tc));
};

void fix()
{
	int a,b;
	scanf("%d%d",&a,&b);
	treap *ta,*tb,*tc;
	
	split(root, a-1, ta, tb);
	split(tb , b-a+1 , tb ,tc );
	
	root= merge(tb , merge(ta,tc));
		
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
				fix();
			else
				ask();
		};
			
	};
	
	return 0;
};

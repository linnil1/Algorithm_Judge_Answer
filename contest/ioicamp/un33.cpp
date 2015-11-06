#include<bits/stdc++.h>
#define lld long long int

#define M 50100

struct treap
{
	treap *l,*r;
	int pri;
	int size;
	char ch,swap;
	treap(){};
	treap(char _ch):l(NULL),r(NULL),pri(rand()),ch(_ch),
					size(1),swap(0){}
};

int size(treap *a){return a ? a->size : 0 ;}

void pull(treap *a)
{
	if(!a)return ;
	a->size = size(a->l) + size(a->r) + 1; 
}
void push(treap *a)
{
	if(!a->swap)return ;
	if(a->l) a->l->swap = !a->l->swap;
	if(a->r) a->r->swap = !a->r->swap;
	a->swap = 0 ;
	std::swap(a->r , a->l );
}

treap* initmerge (treap* a,treap* b)
{
	if(!a || !b) return a? a:b ;
	else if ( a->pri > b->pri)
	{
		a->r = initmerge( a->r , b);
		pull(a);		
		return a;
	}
	else
	{
		b->l = initmerge (a , b->l);	
		pull(b);
		return b;
	}
}

treap* merge(treap *a,treap *b)
{
	
	if(!a || !b)return a?a:b;
	
	treap *t;
	
	if( rand()%(size(a)+size(b)) < size(a) )
	{
		push(a);
		t = new treap(*a); 
		t->r = merge( a->r , b );
	}
	else
	{
		push(b);
		t = new treap(*b);
		t->l = merge(a,b->l);	
	}
	pull(t);
	return t;
}

void split (treap* t , int key ,treap* &a,treap*& b)
{
	
	if(!t) a = b = NULL ; 
	else if(size(t->l) < key )
	{
		push(t);
		a = new treap(*t) ;
		split(t->r , key - 1 - size(t->l) , a->r , b);
		pull(a);		
	}	
	else
	{		
		push(t);
		b = new treap(*t) ;
		split(t->l , key , a , b->l );		
		pull(b);
	}
}
treap *root;

//srand(time(NULL));
//root = NULL ;
void order(treap *a)
{
	if(a->l)order(a->l);
	putchar(a->ch);
	if(a->r)order(a->r);
}
void ask()
{
	int l,r;
	scanf("%d%d",&l,&r);
	treap *a=NULL,*b=NULL,*c=NULL;
	split(root, l-1 ,a,b);
	split(b, r-l+1 ,b,c);
	
	order(b);
	puts("");
	//root = merge( a, merge(b,c) );
}

void tocpy()
{
	int l,r,m;
	scanf("%d%d%d",&l,&r,&m);
	treap *a=NULL,*b=NULL,*c=NULL;
	split(root, l-1 ,a,b);
	split(b, r-l+1 ,b,c);
	
	
	
	root = merge( a, merge(b,c) );
	puts("zxc");
}

void toswap()
{
	int l,r,m;
	scanf("%d%d%d",&l,&r,&m);
	treap *a=NULL,*b=NULL,*c=NULL;
	split(root, l-1 ,a,b);
	split(b, r-l+1 ,b,c);
	
	b->swap = !b->swap ;
	puts("zxc");
	root = merge( a, merge(b,c) );
}
int main()
{
	freopen("in.txt","r",stdin);
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		
		root = NULL ;
		
		char c[M];
		scanf("%s",c);
		for(int i=0;c[i];++i)		
			root = initmerge(root , new treap(c[i]) );
		
		
		while(m--)
		{
			int t;
			scanf("%d",&t);
			if(t==1)
				ask();
			else if(t==2)
				tocpy();
			else if(t==3)
				toswap();
		};			
		//printf("%d\n",);
	};
	return 0;
};
/*
*/

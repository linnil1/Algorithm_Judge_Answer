#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 10000

struct treap
{
	treap *l,*r;
	int pri,size,val;
	int num,max,min,minnum;
	treap(){};
	treap(int _val,int _num):
		l(NULL),r(NULL),pri(rand()),size(1)
		{ val=max=min= _val;
		  num=minnum = _num;}
	void pull();
	
}*root;

int tosize(treap *a){ return a ? a->size : 0 ; }
int tomin (treap *a){ return a ? a->min  : 0x7fffffff ; }
int tomax (treap *a){ return a ? a->max  : 0x80000000 ; }
int tonum (treap *a){ return a ? a->minnum  : 0x7fffffff ; }

void treap::pull()
{
	size = tosize(l) + tosize(r) + 1 ;
	min = std::min( std::min( tomin(l) , tomin(r) ) , val );
	max = std::max( std::max( tomax(l) , tomax(r) ) , val );
	minnum = std::min( std::min( tonum(l) , tonum(r) ) , num );
}


treap* merge(treap *a,treap *b)
{
	if(!a || !b) return a ? a:b;
	else if(a->pri > b->pri)
	{
		a->r = merge( a->r, b);
		a->pull();
		return a;
	}
	else
	{
		b->l = merge( a, b->l);
		b->pull();
		return b;
	}
}

void split(treap *t,int key,treap* &a,treap* &b)
{
	if(!t) a=b=NULL;
	else if( tosize(t->l) < key)
	{
		a = t ;
		split(t->r , key-tosize(t->l)-1 , a->r , b);
		a->pull();
	}
	else
	{
		b = t ;
		split(t->l , key , a , b->l );
		b->pull();
	}
}


void makenum(int *c,int *num,int n)
{
	std::map<int,std::queue<int> > m ;
	for(int i=n;i>0;--i)
	{
		m[c[i]].push(i);
		
		if(m[c[i]].size() == 4 )
		{
			num[i] = m[c[i]].front();
			m[c[i]].pop();
		}
		else
			num[i] = n+1;
	}
}

void order(treap *a)
{
	if(!a)
		return ;
	order(a->l);
	printf("%d ",a->val);
	order(a->r);
}
void ask()
{
	int x,y;
	scanf("%d%d",&x,&y);
	treap *ta=NULL,*tb=NULL,*tc=NULL;
	split(root,x-1,ta,tb);
	split(tb,y-x+1,tb,tc);
	
	//printf("%d",tonum(tb) );
	//order(tb);
	printf("%c",tonum(tb)>y && tomax(tb)-tomin(tb)<=51400 ?'Y':'N');
	
	root = merge ( ta , merge (tb,tc));
	
}

int main()
{
	srand(time(NULL));
	freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int arr[n+1],num[n+1];
		
		for(int i=1;i<=n;++i)
			scanf("%d",arr+i);
		
		makenum(arr,num,n);
		
		/*for(int i=1;i<=n;++i)
			printf("%d ",num[i]);
		puts("");*/
		
		root=NULL;
		for(int i=1;i<=n;++i)
			root = merge( root, new treap (arr[i],num[i]) );
		
		while(m--)
			ask();		
		puts("");
	};
	return 0;
};
/*
*/

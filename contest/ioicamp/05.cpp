#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define lld long long int

struct treap
{
	treap *l,*r;
	int num,pri;
	lld max,leftmax,rightmax,sum,val;
	treap(){};
	treap(int i,int _val):
		l(NULL),r(NULL),
		num(i), pri(rand()), val(_val) 
		{max=leftmax=rightmax=sum=_val;};
};

#define three(a,b,c)\
	std::max(std::max(a,b),c)
#define four(a,b,c,d)\
	std::max(std::max(std::max(a,b),c),d)
void fix(treap *c)
{
	if(!c)
		return ;
	treap *a=c->l , *b= c->r ;
	treap *em = new treap(-1,-20001);
	em -> sum =0;
	if(!a) a = em;
	if(!b) b = em;
	c->sum = a->sum + b->sum + c->val ;
	c->rightmax = four( b->rightmax , b->sum + c->val , b->sum + c->val + a->rightmax , c->sum); 
	c->leftmax  = four( a->leftmax  , a->sum + c->val , a->sum + c->val + b->leftmax  , c->sum); 
	c->max = three   ( four ( c->val , c->rightmax , c->leftmax , c->sum),
					  std::max ( a->max , b->max  ) ,
					  three ( a->rightmax + c->val + b->leftmax , a->rightmax + c->val ,c->val + b->leftmax)
					  
					  );
	delete em;
	
	
};
treap* merge(treap *a,treap *b)
{
	//printf("m");
	if(!a || !b) return a ? a:b ;
	if( a->pri > b->pri)
	{
		a->r = merge(a->r , b);
		fix(a);
		return a;
	}
	else
	{
		b->l = merge(a , b->l);
		fix(b);
		return b;
	};			
};

void spilt(treap *t,int sp ,treap *&a,treap *&b)
{
	//printf("s");
	if(!t)a=b=NULL;
	else if(t->num <= sp )
	{
		a = t ;
		spilt(t->r , sp , a->r ,b);	
		fix(a);	
	}
	else
	{
		b = t;
		spilt(t->l , sp, a , b->l);		
		fix(b);
	};			
};

void low(treap *a)
{
	if(!a)
		return ;
	low(a->l);
	printf("%d %d %d %d\n",a->num,a->leftmax,a->rightmax,a->max);
	
	low(a->r);
	
};
int main()
{
	srand(time(NULL));
	int count=1000;
	while(~scanf("%d",&count))
	while(count--)
	{
		int a,b;
		treap *r=NULL;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;++i)
		{
			int t;
			scanf("%d",&t);
			r = merge(r,new treap(i,t));
		};
		while(b--)
		{
			int op,x,y;
			treap *ta=NULL,*tb=NULL;
			scanf("%d%d%d",&op,&x,&y);			
			if(op==1)
			{
				spilt(r,x-1,ta,r);
				spilt(r,y,r,tb);
				printf("%lld\n",r->max);				
			}
			else
			{
				spilt(r,x-1,ta,r);
				spilt(r,x,r,tb);
				r->val = y ;
			};
			//low(r);puts("!!");
			r=merge(merge(ta,r),tb);
		}
	};
	return 0;
}


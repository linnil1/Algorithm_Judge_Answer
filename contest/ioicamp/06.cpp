#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 100100

int ori[M];

lld three(lld a,lld b,lld c)
{
	return std::max(std::max(a,b),c);
}

struct seg
{
	lld max,rmax,lmax,sum;
	seg *l,*r;
	seg(){}
	seg(seg *a)
	{
		max = a->max ;
		lmax= a->lmax;
		rmax= a->rmax;
		sum = a->sum ;
	}
	seg(lld val)
		{max=rmax=lmax=sum=val;}
	void init(int val)
	{
		max=rmax=lmax=sum=val;
	}
	
	void pull()
	{
		sum = l->sum + r->sum ;
		lmax = three(l->lmax , l->sum + r->lmax , l->sum + r->sum);
		rmax = three(r->rmax , r->sum + l->rmax , l->sum + r->sum);
		max = three(three( l->max , r->max , l->rmax+r->lmax),lmax,rmax);
	}
};

seg* build(int l,int r)
{
	seg* now = new seg();
	if(l==r)
	{
		now->init(ori[l]);
		return now;
	}
	int mid = (l+r)>>1;
	now->l = build(    l,mid);
	now->r = build(mid+1,  r);
	now->pull();
	return now;		
}
seg* ask(seg* a,int l,int r,int x,int y)
{
	if(l>y || r<x)
		return new seg(-2147483648);
	if(x<=l && r<=y)
		return new seg(a) ;
	
	seg *now = new seg (a);	
		
	int mid = (l+r)>>1;
	now->l = ask(a->l,    l,mid,x,y) ; 
	now->r = ask(a->r,mid+1,  r,x,y) ;
	now->pull();
	
	delete now->l;
	delete now->r;
	return now;
}

void fix(seg *a,int l,int r,int i,int v)
{
	if(l==r)
	{
		a->init(ori[l]=v);
		return ;
	}
	int mid = (l+r)>>1;
	if(mid >=i) 
		fix(a->l,    l,mid,i,v);
	else
		fix(a->r,mid+1,  r,i,v);
	a->pull();	
}

int main()
{
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
		for(int i=0;i<n;++i)
			scanf("%d",ori+i);
		seg *root = build(0,n-1);
		
		while(m--)
		{
			int t;
			scanf("%d",&t);
			if(t==1)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				--x;--y;
				printf("%lld\n",ask(root,0,n-1,x,y)->max);
			}
			else 
			{
				int i,v;
				scanf("%d%d",&i,&v);
				--i;
				fix(root,0,n-1,i,v);
			}
		}
	};
	return 0;
};
/*
*/

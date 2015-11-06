#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

#define themax(a,b,c) std::max(std::max(a,b),c)


int tree[M],
	road[M];
	
struct seg 
{
	seg *l,*r;
	
	int lh,rh,sum;
	int max,lmax,rmax;
	
	seg(){};
	seg(int a){lh=rh=sum=max=lmax=rmax=a;}
	
	void pull(int i)
	{
		lh = l->lh;
		rh = r->rh;
		sum = l->sum + r->sum + road[i];
		
		 max = themax( l->max , r->max , 	l->rmax + r->lmax - l->rh - r->lh + road[i] );
		lmax = themax( l->lmax , l->lh +  l->sum + road[i] + r->lmax - r->lh , l->lh +  sum + r->rh);
		rmax = themax( r->rmax , r->rh +  r->sum + road[i] + l->rmax - l->rh , r->rh +  sum + l->lh);
		 max = themax( max , lmax , rmax);
	}	
};

	
seg* build(int a,int b)
{	
	seg *now = new seg;
	if(a==b)
	{
		now->lh  = now-> rh =
		now->lmax = now->rmax = now->max = tree[a] ;
		now->sum = 0 ;
		return now;
	}
	int mid=(a+b)>>1;
	now->l = build(    a,mid);
	now->r = build(mid+1,  b);
	now->pull(mid);
	return now;
}

seg *find(seg *r,int a,int b,int &x,int &y)
{
	if( b<x || y<a)
		return new seg(0);
	if( x<=a && b<=y)
		return r;
	
	seg *now = new seg;
	int mid = (a+b)>>1;
	now->l = find(r->l,    a,mid,x,y);
	now->r = find(r->r,mid+1,  b,x,y);
	now->pull(mid);
	return now;	
}
int main()
{
	freopen("..\\..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,m;
	while(~scanf("%d%d",&n,&m))
	#endif	
	{		
		for(int i=1;i<=n;++i)
		{
			scanf("%d",road+i);
			road[n+i] = road[i];
		};
		for(int i=1;i<=n;++i)
		{
			scanf("%d",tree+i);
			tree[n+i] = tree[i]*=2;
		};
		
		seg *root = build(1,2*n);
		
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			--a;++b;
			if(a<=b)
				a+=n;				
			
			std::swap(a,b);
		//	printf("%d %d\n",a,b);
			seg *f = find(root,1,2*n,a,b);
			
			//printf("%d %d\n",f->lmax,f->rmax);
			
			printf("%d\n",f->max);				
		}
		
	};
	return 0;
};
/*
*/

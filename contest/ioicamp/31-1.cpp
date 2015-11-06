#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 100100

struct seg
{
	static seg mem[5*M],*pmem;
	seg *r,*l;
	int minnum,max,min;
	seg():minnum(0x7fffffff),min(0x7fffffff),max(0x80000000){};
	
	seg(int _num,int _val):
		minnum(_num){max=min=_val;};
		
	void pull()
	{
		minnum = std::min ( r->minnum , l->minnum);
		max    = std::max ( r->max    , l->max   );
		min    = std::min ( r->min    , l->min   );
	}
	
}*root,seg::mem[5*M],*seg::pmem= seg::mem;



int arr[M],num[M];
seg* built(int l,int r)
{
	if(l==r)
		return new  seg(num[l],arr[l]);	
	seg *now = new  seg ;	
	int mid = (l+r)>>1;	
	now->l = built(    l,mid);
	now->r = built(mid+1,  r);
	now->pull();
	return now ;
}

seg* find(seg* a,int l,int r,int x,int y)
{
	if(r<x || y<l)
		return new (seg::pmem++) seg;
	if(x<=l && r<=y)
		return new (seg::pmem++) seg(*a);
		
	seg *now = new (seg::pmem++) seg ;
	
	int mid = (l+r)>>1;	
	now->l = find(a->l,    l,mid,x,y);
	now->r = find(a->r,mid+1,  r,x,y);
	now->pull();
	return now ;
}

void ask(int n)
{
	int x,y;
	scanf("%d%d",&x,&y);
	--x;--y;
	seg *ans = find(root,0,n-1,x,y);
	
	seg::pmem = seg::mem;
	
	printf("%c",ans->minnum > y && ans->max - ans->min <= 51400 ?'Y':'N');
}

void makenum(int *c,int *num,int n)
{
	std::unordered_map<int,std::queue<int> > m ;
	for(int i=n-1;i>=0;--i)
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

int main()
{
	srand(time(NULL));
	//freopen("in.txt","r",stdin);
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
			scanf("%d",arr+i);
		
		makenum(arr,num,n);
		
		/*for(int i=1;i<=n;++i)
			printf("%d ",num[i]);
		puts("");*/
		
		root = built(0,n-1);
		while(m--)
			ask(n);		
		puts("");
	};
	return 0;
};
/*
*/

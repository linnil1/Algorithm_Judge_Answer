#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 1001000

std::vector<int> v[M] ;
int city[M];

bool ok(int s,int k,int now,int n)
{
	
}

int find(int s,int k,int n)
{
	ll l=INT_MAX , r=0;
	for(int i=1;i<=n;++i)
	{
		r+=city[i];
		if( city[i] < l )
			l = city[i] ;
	};
	++r;
	
	while(l+1<r)
	{
		ll mid = (l+r)>>1;
		
		if(ok(s,k,mid,n))
			l = mid ;
		else
			r = mid ;
	};
	printf("%lld\n",l);
		
	}
	
	
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,k;
	while(~scanf("%d%d",&n,&k))
	#endif	
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%d",city+i);
			v[i] = std::vector<int>();
		};
		for(int i=1;i<=n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		//
		int s;
		for(int i=1;i<=n;++i)
			if(v[i].size()==1)
				{s=i;break;}
		
		printf("%d\n",find(s,k,n));		
		
	};
	return 0;
};
/*
*/

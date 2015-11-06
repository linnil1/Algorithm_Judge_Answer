#include<bits/stdc++.h>
#define ll long long int
#define yesT
#define M 100100

int arr[2*M];
struct strans
{
	int x,y,bid,num;
	bool operator < (const strans &a)const
	{
		return bid != a.bid ? bid < a.bid : y < a.y ;
	}
}ans[2*M];
ll vans[2*M];

int map[M];
void find(ll &sum,int &l,int &r,int &i)
{
	int &x = ans[i].x,
		&y = ans[i].y;
		
	while(r < y)
	{
		++r;
		sum+=( arr[r] - map[ arr[r] ]++ );
	}
	while(l > x)
	{
		--l;
		sum+=( arr[l] - map[ arr[l] ]++ );
	}
	while(l < x)
	{
		sum-=( arr[l] - (--map[ arr[l] ]) );
		++l;
	}
	
	vans[ ans[i].num ] = sum ;	
}
//Â÷´²¤Æ 
void scat(int *arr,int n)
{
	std::vector< std::pair<int,int> > v;
	for(int i=0;i<n;++i)
		v.push_back( std::make_pair(arr[i],i) );
		
	std::sort(v.begin(),v.end());
	for(int i=0,now=-1,here=-1;i<n;++i)
		if(v[i].first == here)
			arr[v[i].second] = now ;
		else
		{
			arr[v[i].second] = ++now ;
			here = v[i].first;
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
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		for(int i=0;i<n;++i)
			arr[i+n]=arr[i];
		
		int k = (int)sqrt(n);
		
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&ans[i].x,&ans[i].y);
			--ans[i].x;
			--ans[i].y;
			if(ans[i].y < ans[i].x)
				ans[i].y += n ;
			ans[i].bid = ans[i].x / k;
			ans[i].num = i ;
		};
		
		std::sort(ans,ans+m);
		
		ll sum ;
		for(int i=0,l,r,now=-1;i<m;++i)
			if(now == ans[i].bid)
				find(sum,l,r,i);
			else
			{
				now = ans[i].bid ;
				l = now * k ;
				r = l - 1 ;
				for(int i=0;i<M;++i)
					map[i] = 0 ;
				sum = 0 ;
				find(sum,l,r,i);
			}
			
		for(int i=0;i<m;++i)
			printf("%lld\n",vans[i]);
	};
	return 0;
};
/*
*/

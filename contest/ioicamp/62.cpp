#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 101000


int arr[M],bok[M],k;
int v[M];


struct strask
{
	int num,bid,x,y;
	bool operator < (const strask &b)const
	{
		return bid != b.bid ? bid < b.bid : y < b.y ;
	}
};
/*bool operator < (strask a,strask b)
{
	return a.bid != b.bid ? a.bid < b.bid : a.y < b.y ;
}*/
int um[M],umsize;

strask ans[M];
void play(int &l,int &r,int &i)
{
	int &x=ans[i].x,
		&y=ans[i].y;
	
	while(r<y)
	{		
		++um[arr[++r]];
		if(um[arr[r]] == 1)
			++umsize;
	}
	while(l>x)
	{	
		++um[arr[--l]];
		if(um[arr[l]] == 1)
			++umsize;
	};
	while(l<x)
	{
		--um[arr[l]];
		if(!um[arr[l]])
			--umsize;
		++l;
	}
		
	v[ans[i].num] = umsize;
	
	/*for(std::pair<int,int> pii : um)
		printf("%d %d\n",pii.first,pii.second);
	printf("%d\n",um.size());*/
}
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
			
		
		k = (int)sqrt(n);
		//build(n);
		
		
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&ans[i].x,&ans[i].y);
			--ans[i].x;
			--ans[i].y;
			ans[i].num = i ;
			ans[i].bid = ans[i].x/k;					
		}
		std::sort(ans,ans+m);
		scat(arr,n);
		int now=-1;
		for(int i=0,l,r;i<m;++i)
		{		
			if(ans[i].bid != now)
			{
				now = ans[i].bid ;
				l = now * k ;		
				r = l -1;					
				for(int i=0;i<n;++i)
					um[i]=0;	
				umsize=0;		
			}
			play(l,r,i);
		};
		
		for(int i=0;i<m;++i)
			printf("%d\n",v[i]);
		
	};
	return 0;
};
/*
*/

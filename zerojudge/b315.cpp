#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 101000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

ll arr[M];

ll count(ll n,ll max)
{
	if(max==-1)
		return 0;
	int l=-1;
	ll sum=0,now=0;
	
	for(int i=0;i<n;++i)
	{
		now += arr[i] ;
		if(now <= max)
			sum+=i-l;
		else
		{
			while(now>max)
				now-=arr[++l];
			sum+=i-l;
		}
	}
	return sum;	
}

ll find(int n,ll k)
{
	std::sort(arr,arr+n);
	ll sum=arr[n-1]-arr[0];
	for(int i=1;i<n;++i)
		arr[i-1]=arr[i]-arr[i-1];
	--n;
	ll l=-1,r=sum,mid;
	while(l+1<r)
	{
		mid = (l+r)>>1;
		if(count(n,mid)>=k)
			r = mid;
		else
			l = mid;
	}
	return r;	
}

int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,k;
	while(~scanf("%d%d",&n,&k))
	#endif	
	{
		for(int i=0;i<n;++i)
			scanf("%lld",arr+i);
		printf("%lld\n",find(n,(ll)n*(n-1)/2-k+1));
	};
	return 0;
};
/*
*/

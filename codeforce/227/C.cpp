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

#define tonew(i) wh[arr[i]] = i;
int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,t,k;
	while(~scanf("%d%d%d",&n,&t,&k))
	#endif	
	{
		int arr[M],wh[M];
		for(int i=0;i<n;++i)
		{
			scanf("%d",arr+i);
			tonew(i);
		};
		
		ll sum=t;
		while(t--)
		{
			int now;
			scanf("%d",&now);
			int where = wh[now];
			sum+=where/k;
			
			if(where)
			{
				std::swap( arr[where] ,arr[where-1]);
				tonew(where);
				tonew(where-1);
			};
			
		}
		printf("%I64d\n",sum);
		
	};
	return 0;
};
/*
*/

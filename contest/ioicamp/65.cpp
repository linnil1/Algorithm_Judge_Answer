#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 1100
int prim[M],ps,
	arr [M],num,
	ans,n;
	
void big(int i,int *now,int nows)	
{
	if(i<0)
	{
		bool t[n+1];
		memset(t,0,sizeof(t));
		for(int i=0;i<nows;++i)
			for(int j=now[i];j<=n;j+=now[i])
				t[j] = !t[j];
		
		int sum=0;
		for(int i=0;i<ps;++i)
		{		
			int a=0,b=0;
			for(int j=prim[i];j<=n;j+=prim[i])
				t[j] ? ++a : ++b;
			if(b>a)
				sum+=(b-a);
		}				
		
		
		for(int i=1;i<=n;++i)
			sum+=t[i];
		
		if(sum > ans)
			ans = sum;
		
		return ;
	}
	
	big(i-1,now,nows);
	now[ nows++ ] = arr[i];
	big(i-1,now,nows);
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
		int k;
		scanf("%d%d",&n,&k);
		num=ps=0;
		while(k--)
		{
			int t;
			scanf("%d",&t);
			if(t>31)
				prim[ps++]=t;
			else
				arr[num++]=t;
		}
		
		ans=0;
		int now[M],nows=0;
		big(num-1,now,nows);
		
		printf("%d\n",ans);		
		
	};
	return 0;
};
/*
*/

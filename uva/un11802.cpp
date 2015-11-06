#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 10000

int cal(int n,int i)
{
	int sum=0;
	while(n)
	{
		sum += n/i;
		n/=i;
	}
	return sum;
}

int find(int n,int k)
{
	int l = 2 , r = n+1;
	while(l+1<r)
	{
		int mid = (l+r)>>1;
		if( cal(n,mid) >= k )
			l = mid;
		else
			r = mid;
	}
	return l;
}

void pr(int n)
{
	int all=1;
	for(int i=2;i<=n;++i)
		all*=i;
		
	int count=0;
	for(int i=2;i<=10000;++i)
		if(all%(i*i)==0 && all/i/i%i )
	{
		++count;
		printf("%d :",i);
		int now = all;	
		
		while(now)
		{		
			printf("%2d ",now%i);
			now/=i;
		};
		puts("");
	};
	printf("%d\n",count);
}
int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	pr(12);
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n,k;
		scanf("%d%d",&n,&k);
		
		
		
		int low = find(n,k),
			big = find(n,k+1);
		
		printf("%d %d\n",big,low);		
	};
	return 0;
};
/*
*/

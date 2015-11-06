#include<cstdio>
#include<algorithm>
int find(int *c,int n,int num,int want)
{
	int now=0;
	for(int i=0;i<num;++i)
		now+=c[i];
	int sum=0;
	if(now==want)
		++sum;
	for(int i=num;i<n;++i)
	{
		now=now-c[i-num]+c[i];
		if(now==want)
			++sum;
	};
	return sum;
		
		
};
int main()
{
	int n,p,q;
	while(~scanf("%d%d%d",&n,&p,&q))
	{
		int c[n];
		for(int i=0;i<n;++i)
			scanf("%d",c+i);
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			int t=i*p;
			if(t%q==0)
				sum+=find(c,n,i,t/q);			
		};
		printf("%d\n",sum);
			
	};
	return 0;
};

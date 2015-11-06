#include<cstdio>
#include<algorithm>
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int c[n];
		for(int i=0;i<n;++i)
			scanf("%d",c+i);
		std::sort(c,c+n);
		int sum[n+1];
		sum[0]=0;
		for(int i=1;i<n;++i)
			sum[i]=sum[i-1]+c[i-1];
		
		int big=-1;
		for(int i=n-1;i>=0;--i)
			if(sum[i] >= c[i] )
			{
				big=i;
				break;
			}
		printf("%d\n",big+1);
	};
	return 0;
};

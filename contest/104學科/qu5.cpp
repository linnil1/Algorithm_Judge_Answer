#include<cstdio>
#include<algorithm>
#define M 2097150
#define lld long long int
lld num[M];

int find(lld a)
{
	int i;
	for(i=0;i<M;++i)
			num[i]=(lld)i*i*i;
		for(i=1;num[i]<a;++i);
		//printf("%d",i);
		int j=1;
		for(;num[i]-num[i-1]<=a;++i)
			for(;num[i]-num[j]>=a;++j)
				if(num[i]-num[j]==a)
				{
					printf("%d %d\n",i,j);
					return 1;
				}
	return 0;
};
int main()
{
	lld a,b;
	while(~scanf("%I64d",&a))
	{
		int t,m,i=1;
		if(!find(a))
			puts("No solution");
	};
	return 0;
};

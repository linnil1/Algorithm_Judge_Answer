#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int q,w,e,r,t,a;
	while(~scanf("%d",&a))
	{
		int c[a];
		for(q=e=r=0;q<a;++q)
		{
			scanf("%d",&c[q]);
			e+=c[q]*q;
			r+=c[q];
		};
		if(e%r)
			printf("%d %d\n",e/r+1,e/r+2);
		else
			printf("%d\n",e/r+1);
	};
	return 0;
};

#include<stdio.h>
#include<cmath>
#include<algorithm>
int a,b;
double max;
double c[1010];
void dfs(int now,int num,int *has,int *use)
{
	int q;
	
	if(num==b)
	{
		for(q=1;q<b;++q)
			if(c[has[q]]-c[has[q-1]]>3.14159)
			return ;
		has[b]=has[0];
		double want=0;
		for(q=0;q<b;++q)
		{
			want+=(cos(c[has[q]])*sin(c[has[q+1]])-sin(c[has[q]])*cos(c[has[q+1]]));
		};
		want/=2;
		if(want<0)
			want=-want;
		
		if(want>max)
			max=want;
		return ;
	};
	if(now>=a)
		return ;
	for(q=now;q<a;++q)
		if(use[q])
		{
			use[q]=0;
			has[num]=q;
			dfs(q+1,num+1,has,use);
			use[q]=1;
		};
};
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int q,w,e,r,t;
	while(~scanf("%d%d",&a,&b))
	{
		for(q=0;q<a;++q)
			scanf("%lf",&c[q]);
		std::sort(c,c+a);
		int has[a+2],use[a+2];
		max=0;
		dfs(0,0,has,use);		
		printf("%.4lf\n",max);	
	};
	return 0;
};

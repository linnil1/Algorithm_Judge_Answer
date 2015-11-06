#include<stdio.h>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int q,w,e,r,t,a,b;
	while(~scanf("%d",&a)&&a)
	{
		int c[a],con[a],all[a],mon[a],now,max;
		for(q=e=0;q<a;++q)
		{
			scanf("%d",&c[q]);
			e+=c[q];
		};
		con[0]=0;
		for(q=1;q<a;++q)
			scanf("%d",&con[q]);
		
		max=0;
		for(q=0;q<a;++q)
			all[q]=mon[q]=0;
		for(q=a-1;q>=0;--q)
		{
			now=c[q]*(e-1)+(c[q]+mon[q])*(e-c[q]-mon[q])+all[q];
			all[con[q]]+=(c[q]+mon[q])*(e-c[q]-mon[q]);
			mon[con[q]]+=(c[q]+mon[q]);
			//printf("%d %d %d %d\n",now,c[q]*(e-1),c[q]*(e-c[q]),all[q]);
			if(now>max)
				max=now;
		};
		printf("%d\n",max);
		
	};
	return 0;
};

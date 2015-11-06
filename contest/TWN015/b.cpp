#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int q,w,e,r,t,a,b,sx,sy,ex,ey;
	while(~scanf("%d%d",&a,&b))
	{
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		int c[a+1][b+1];
		for(q=0;q<=a;++q)
			for(w=0;w<=b;++w)
				c[q][w]=0;
		for(q=sx;q<=a;++q)
			c[q][sy]=1;
		for(q=sy;q<=b;++q)
			c[sx][q]=1;
		for(q=sx+1;q<=a;++q)
			for(w=sy+1;w<=b;++w)
				c[q][w]=c[q-1][w]+c[q][w-1]+c[q-1][w-1];
		printf("%d\n",c[ex][ey]);		
	};
	return 0;
};

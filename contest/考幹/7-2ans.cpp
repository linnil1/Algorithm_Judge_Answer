#include<stdio.h>
int money(int x)
{
	if(x<0)
	    return 0;
	return (money(x-1)+money(x-2)+650*x*x+7915*x+32198)%15937;
};
#define M 200
int main()
{
	int i,j,k;
	int a,b;
	int d[M+3];
	int *c=&d[2];
	c[-1]=c[-2]=0;
	for(i=0;i<=M;++i)
	    c[i]=(c[i-1]+c[i-2]+650*i*i+7915*i+32198)%15937;
	while(~scanf("%d",&a))
	{
		printf("%d\n",c[a]);
	};
	return 0;
};

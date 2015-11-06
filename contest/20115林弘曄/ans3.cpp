#include<cstdio>
int cal(int x,int *ta,int t)
{
	int sum=0;
	for(int i=0;i<x;++i)
		sum+=t/ta[i];
	return sum;
};
int able(int x,int *ta,int t,int max)
{
	int sum=0;
	for(int i=0;i<x;++i)
		sum+=t/ta[i];
	if(sum>=max)
		return 1;
	else 
		return 0;
};
int main()
{
    int t,x,y,p,p1,q,q1;
    while(~scanf("%d%d%d%d%d%d%d",&t,&x,&y,&p,&p1,&q,&q1))
    {
		p+=p1;
		q+=q1;
		int ta[x],tb[y];
		for(int i=0;i<x;++i)
			scanf("%d",&ta[i]);
		for(int i=0;i<y;++i)
			scanf("%d",&tb[i]);
		t=t-q-p;
		int max=0,quick=0;
		for(int i=0;i<=t;++i)
		{
			int now=cal(x,ta,i);
			if(able(y,tb,t-i,now))	
				if(now>max)
				{
					max=now;
					quick=i;
				}		
		};
		printf("%d\n%d\n",quick+p,max);
	};
    return 0;
};

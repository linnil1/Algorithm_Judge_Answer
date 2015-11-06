#include<stdio.h>
#include<string.h>
#define M 20
void ver(int a,char *c)
{
	int i=0;
	while(a)
	{
		c[i]=a&1;
		a>>=1;
	};
};
void doit()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		int i,sum=0;
		char c[100],d[100];
		memset(c,0,sizeof(c));memset(d,0,sizeof(d));
		ver(a,c);
		ver(b,d);
		
		for(i=0;i<M;++i)
			if(c[i]==d[i])
			    c[i]=0;
			else
			    c[i]=1;
		for(i=M;i>=0;--i)
		    sum=sum*2+c[i];
		printf("%d\n",sum);
	};
};
int main()
{
	int i,j,k;
	int a,b;
	//doit();
	while(~scanf("%d%d",&a,&b))
	{
		printf("%d\n",a^b);
	};
	return 0;
};

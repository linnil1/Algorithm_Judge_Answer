#include<stdio.h>
int main()
{
	int i,j,k,time=1;
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		int c[b];
		for(i=0;i<b;++i)
		    scanf("%d",c+i);
		for(i=1;i<b;++i)
		    for(j=b-1;j>=i;--j)
		        c[j]-=c[j-1];
		while(b>1 && c[b-1]==0)
		    --b;
		while(--a)
			for(i=0;i<=b-2;++i)
			    c[i]+=c[i+1];
		printf("%d\n",c[0]);
	};
	return 0;
};
/*









*/

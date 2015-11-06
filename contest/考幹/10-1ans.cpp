#include<stdio.h>
#define b 6
int main()
{
	int i,j,k,time=1;
	int a;
	while(~scanf("%d",&a))
	{
		int c[b];
		for(i=0;i<b;++i)
		    scanf("%d",c+i);
		for(i=1;i<b;++i)
		    for(j=b-1;j>=i;--j)
		        c[j]-=c[j-1];
		while(--a)
			for(i=0;i<b-2;++i)
			    c[i]+=c[i+1];
		printf("%d\n",c[0]);
	};
	return 0;
};
/*









*/

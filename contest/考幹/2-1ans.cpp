#include<stdio.h>
#include<algorithm>
int main()
{
	int i,j,k;
	int a,b;
	while(~scanf("%d",&a))
	{
		int c[a];
		for(i=0;i<a;++i)
		    scanf("%d",c+i);
		std::sort(c,c+a);
		for(i=0;i<a;++i)
			printf("%d ",c[i]);
		puts("");
	};
	return 0;
};
/*









*/

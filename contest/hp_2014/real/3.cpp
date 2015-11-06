#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n)
	{
		double ans=0;
		if(n<=200 && n>=20)
			ans=1.2*(n-20);
		if(n>200)
			ans=0.9*(n-200)+216;
		printf("%.0lf\n",ans);
			
	}

	return 0;
}


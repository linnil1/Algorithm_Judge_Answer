#include<stdio.h>

int main()
{
	double a,b;
	while(~scanf("%lf%lf",&a,&b))
	{
		printf("%.3lf\n",b*121/60/10/a);
	};

	return 0;
}


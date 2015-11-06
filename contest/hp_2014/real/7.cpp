#include<stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d.%d %d %d %d",&a,&b,&c,&d,&e);
	double w=(6*a+b)*c*d;
	double bl=e*8*10*100;
	double t=3*(w-(w+bl)/2000)/5;
	printf("%.0lf %.0lf\n",t/600,(int)t%600);
	return 0;
}


#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 10000
#define EPS 0.000001
bool big(double a,double b)
{
	return  a-b > -EPS;
}
bool small(double a,double b)
{
	return  a-b < EPS;
}
int main()
{
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int ia,ib;
		scanf("%d%d",&ia,&ib);
		ib-=ia;
		double b=ib,
			   a=ia;
		if( b/a > -0.000049 && b/a < 0 ) 
			printf("%6.2lf%%",-(double)(ib*100)/a+EPS);
		else
			printf("%6.2lf%%",(double)(ib*100)/a+EPS*(-(ib<0)));
		if( big(b/a , 0.1) || small(b/a,-0.07))
			puts(" dispose");
		else
			puts(" keep");
	};
	return 0;
};
/*
*/

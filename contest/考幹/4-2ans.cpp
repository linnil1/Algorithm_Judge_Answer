#include<stdio.h>

int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;a=b;b=t;
	}
	return a;
}
int main()
{
	int i,j,k;
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		printf("%d\n",gcd(a,b));
	};
	return 0;
};
/*









*/

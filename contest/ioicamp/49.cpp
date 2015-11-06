#include<bits/stdc++.h>
#define M 1000000007
#define lld long long int

int main()
{
	int T=100000;
	printf("%d\n",T);
	int x=0,y=0;
	double d = 0 , pl = 6.28 / T;
	while(T--)
	{
		d+=pl;
		printf("%d %d\n",(int)(1000000000*cos(d)),(int)(1000000000*sin(d)));
		
	};
	return 0;
};

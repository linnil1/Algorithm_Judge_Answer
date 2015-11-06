#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 10000

int gcd(int a,int b){ b ? gcd(b,a%b) : a;}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T=1;
	//printf("%d\n",T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n=1000000;
		printf("%d\n",n);
		lld x=-1000000000,y=-1000000000;
		for(int i=1;i<=n;++i)
		{
			x +=  30030 / gcd(30030,i);
			y +=  i / gcd(30030,i);
			if(x>=1000000000 || y>=1000000000)
			{
				printf("%d ",i);
				break;
			}
			//printf("%d %d\n",x,y);
		}
		printf("%I64d %I64d\n",x,y);
	};
	return 0;
};
/*
*/

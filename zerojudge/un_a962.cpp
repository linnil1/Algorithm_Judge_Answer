#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10000

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int sum=0;
		for(int i=1;i<=n;++i)
			printf("%d ",n%i),
			sum += n%i;
		printf("%d\n",sum);
	};
	return 0;
};
/*
*/

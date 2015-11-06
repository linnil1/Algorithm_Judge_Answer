#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 1100


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
		int sum = n * (n-1) * (n-2) / 6 ;
		
		int all=0;
		for(int i=0;i<n;++i)
		{
			int c[3]={0,0,0};
			for(int j=0;j<n;++j)
			{
				int x;
				scanf("%d",&x);
				++c[x];
			}
			all+=c[1]*c[2];
		}
		printf("%d\n",sum-all/2);
	};
	return 0;
};
/*
*/

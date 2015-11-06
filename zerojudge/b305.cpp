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
		double sum=0,ss=0;
		int nn=0;
		for(int i=0;i<n;++i)
		{
			int n;
			double u,s;
			scanf("%d%lf%lf",&n,&u,&s);
			nn += n ;
			sum += u*n;
			ss +=( s*s + u*u )*n;
		}
		double avg = sum/nn ;
		printf("%d %.2lf %.2lf\n",nn,avg,sqrt(ss/nn-avg*avg));
	};
	return 0;
};
/*
*/

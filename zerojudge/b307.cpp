#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 10000
#define MOD 10007

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
		ll x,y,t;
		scanf("%lld%lld%lld",&x,&y,&t);
		x = (x-y+MOD)%MOD ;
		x = x * t % MOD ;
		if(x==0)
			puts("SAFE");
		else
			puts("BOOM");
	};
	return 0;
};
/*
*/

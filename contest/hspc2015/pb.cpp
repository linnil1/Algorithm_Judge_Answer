#include<bits/stdc++.h>
#define ll long long int
#define M 1000000

int main()
{
	ll f[300],*fib = &f[150];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<140;++i)
		fib[i] = fib[i-1]+fib[i-2];	
	for(int i=-1;i>=-140;--i)
		fib[i] = fib[i+2] -fib[i+1];	
	int n;
	while(~scanf("%d",&n)){
		printf("%lld\n",fib[n]);
	}
	return 0;
}

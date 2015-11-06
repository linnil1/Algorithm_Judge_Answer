#include<bits/stdc++.h>
#define ll long long int

#define M 10000


int main()
{
	/*int T;
	scanf("%d",&T);
	while(T--)*/
	int a,b,n;
	while(~scanf("%d%d%d",&a,&b,&n))
	{		
		a= std::abs(a) + std::abs(b);
		if( (a>n) || ( (n-a)%2==1) )
			puts("No");
		else		
			puts("Yes");
	};
	return 0;
};
/*
*/

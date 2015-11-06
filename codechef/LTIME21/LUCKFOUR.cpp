#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 10000

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d\n",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		char c;int sum=0;
		while( ( c=getchar() ) != '_' && c!= '\n' )
			if(c=='4')
				++sum;
		printf("%d\n",sum);
	};
	return 0;
};
/*
*/

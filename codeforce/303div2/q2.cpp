#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string


int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	char a[M],b[M];
	while(~scanf("%s%s",a,b))
	#endif	
	{
		int sum=0;
		for(int i=0;a[i];++i)
			if(a[i]!=b[i])
				++sum;
		if(sum%2)
		{
			puts("impossible");
			continue;
		}
		sum/=2;
		for(int i=0;a[i];++i)
			if(sum&&a[i]!=b[i])
			{
				--sum;
				putchar(b[i]);
			}
			else
				putchar(a[i]);
		puts("");
	};
	return 0;
};
/*
*/

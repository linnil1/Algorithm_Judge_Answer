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
	int k,w,n;
	while(~scanf("%d%d%d",&k,&w,&n))
	#endif	
	{
		ll all = (ll)n*(n+1)/2*k;
		if(all>=w)
			printf("%I64d\n",all-w);
		else
			printf("0\n");
	};
	return 0;
};
/*
*/

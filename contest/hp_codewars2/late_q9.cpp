#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100000
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
	int n;
	int dp[32];
	dp[1]=1;dp[2]=2;dp[3]=4;
	for(int i=4;i<31;++i)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		
	while(~scanf("%d",&n))
	#endif	
	{		
		printf("%d\n",dp[n]);
	};
	return 0;
};
/*
*/

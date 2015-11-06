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
	while(~scanf("%d",&n))
	#endif	
	{
		int sum=0;
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		if(n==1)
		{
			printf("2\n");
			continue;
		}
		sum=4;
		for(int i=3,j=4;i<=n;i++,j+=2)
			sum+=j;
			
		printf("%d\n",sum);
	};
	return 0;
};
/*
*/

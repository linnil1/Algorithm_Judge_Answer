#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10000
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
	int n,m;
	while(~scanf("%d%d",&n,&m))
	#endif	
	{
		int t=std::min(n/2,m);
		
		int sum = t;
		n -= t*2;
		m -= t;
		if( n==1 && m>=2)
		{
			++sum;
			--n;
			m-=2;
		}
		
		int k = std::min(m/3,t);
		
		sum+=k;
		printf("%d\n",sum);
		
		
		
		
	};
	return 0;
};
/*
*/

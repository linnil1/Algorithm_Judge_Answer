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

ll cal(int a)
{
	return (ll)a*(a-1)/2;
}

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
	//while(~scanf("%d",&n))
	#endif	
	{
		int arr[26];
		for(int i=0;i<26;++i)
			scanf("%d",arr+i);
		
		char ch[M];
		ll sum[M];
		int n;
		scanf("%s",ch);
		sum[0]=0;
		for(int i=n=0;ch[i];n=++i)
			sum[i+1] = sum[i] + arr[ch[i]-'a'] ;
		
		std::map<ll,int> whe[26];
		
		ll all=0;
		for(int i=0;ch[i];++i)
		{
			int now = ch[i]-'a';
			all += whe[now][sum[i]];
			++whe[now][sum[i+1]];
		};				
		
		
		printf("%I64d\n",all);
		
	};
	return 0;
};
/*
*/

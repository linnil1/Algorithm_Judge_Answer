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
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int arr[n];
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		std::sort(arr,arr+n);
		ll sum=0;
		for(int i=1;i<n;++i)
			if(arr[i]<=arr[i-1])
			{
				sum+=(arr[i-1]+1-arr[i]);
				arr[i] = arr[i-1]+1;
			}
		printf("%I64d\n",sum);
	};
	return 0;
};
/*
*/

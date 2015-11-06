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
		int arr[M];
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		std::sort(arr,arr+n);
		int tot=0;
		for(int i=0,sum=0;i<n;++i)
			if(arr[i]>=sum)
			{
				++tot;
				sum+=arr[i];
			}
		printf("%d\n",tot);
	};
	return 0;
};
/*
*/

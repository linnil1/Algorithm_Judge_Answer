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

void find(int *arr,int n)
{
	int tmp[n];
	for(int i=0;i<n-1;++i)
		scanf("%d",tmp+i);
	std::sort(tmp,tmp+n-1);
	int i;
	for(i=0;i<n && tmp[i]==arr[i];++i);
	printf("%d\n",arr[i]);
	for(i;i<n-1;++i)
		arr[i]=arr[i+1];
		
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
	while(~scanf("%d",&n))
	#endif	
	{
		int arr[n];
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		std::sort(arr,arr+n);
		
		find(arr,n);
		find(arr,n-1);
		
	};
	return 0;
};
/*
*/

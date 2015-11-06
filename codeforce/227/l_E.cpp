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

int find(int *arr,int &n,int &k,int &i,int &l,int &r,int &sum)
{
	l=INT_MIN,r=INT_MAX,sum=1;
	if(i-k >=0)
		l = arr[i-k];
	int j = i+k;
	while(j<n && arr[j]==INT_MAX)
		j += k,++sum;
	if(j<n)
		r = arr[j];
}
int change(int &l,int &r,int &sum)
{
	if(l >= -sum/2)
		return l+1;
	if(r <= (sum-1)/2 ) 
		return r-sum;
	
	return -sum/2;	
}

bool ok(int *arr,int &n,int &k)
{
	for(int i=0;i<k;++i)
		for(int j=i+k;j<n;j+=k)
			if(arr[j-k] >= arr[j])
				return 0;
	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,k;
	while(~scanf("%d%d",&n,&k))
	#endif	
	{
		int arr[n];
		char ch[15];
		for(int i=0;i<n;++i)
		{
			scanf("%s",ch);
			if(ch[0]=='?')
				arr[i] = INT_MAX;
			else
				arr[i] = atoi(ch);
		};
		
		for(int i=0;i<n;++i)
			if(arr[i] == INT_MAX)
			{
				int l,r,sum;
				find(arr,n,k,i,l,r,sum);
				int f=change(l,r,sum);					
				for(int j=0;j<sum;++j)
					arr[i+j*k] = f++;
			}	
		
		if(ok(arr,n,k))
		{
			for(int i=0;i<n;++i)
				printf("%d ",arr[i]);
			puts("");
		}	
		else
			puts("Incorrect sequence");
		
		
	};
	return 0;
};
/*


*/

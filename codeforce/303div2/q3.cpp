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
		int x[n],h[n];
		for(int i=0;i<n;++i)
			scanf("%d%d",x+i,h+i);
		
		int sum=1;//first
		// left x[i] x[i+1]
		for(int i=1,left=x[0];i<n-1;++i)
			if(x[i]-h[i]>left)//to left
			{
				left=x[i];
				++sum;
			}
			else if(x[i]+h[i]>=x[i+1])//cant left and right
			{
				left=x[i];
			}
			else if(x[i]+h[i]<x[i+1])//both
			{
				++sum;
				left = x[i]+h[i];
			}
		if(n>1)
			++sum;//the least
		printf("%d\n",sum);
			
	};
	return 0;
};
/*
*/

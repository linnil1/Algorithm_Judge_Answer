#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10000010
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
//using namespace std;

int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		
		std::bitset<M> b;
		while(n--)
		{			
			int a;
			scanf("%d",&a);
			b[a]=1;		 
		}
		
		for(int i=0,count=0;i<M;++i)
			if(b[i])
			{
				if(count++%10==0)
					printf("%d ",i);
			};
		puts("");
	};
	return 0;
};
/*
26min bitset
*/

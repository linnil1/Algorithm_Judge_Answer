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
	int r,t;
	while(~scanf("%d%d",&r,&t))
	#endif	
	{
		int c[t];
		for(int i=0;i<t;++i)
			scanf("%d",c+i);
			
		int sum=0;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<t;++j)
				if(c[j]==i)
				{
					if(j+1>=t || c[j+1]!=i)
						++sum;
					++c[j];
				}						
		}
		printf("%d\n",sum);
	};
	return 0;
};
/*
*/

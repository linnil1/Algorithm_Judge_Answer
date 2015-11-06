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
		vi v;
		for(int i=0;i<n;++i)
		{
			int ok=1;
			for(int j=0,a;j<n;++j)
			{
				scanf("%d",&a);
				if(a==1 || a==3)
					ok=0;
			}
			if(ok)
				v.pb(i+1);
		};
		
		printf("%d\n",v.size());
		for(int i=0;i<v.size();++i)
			printf("%d ",v[i]);
		puts("");
		
	};
	return 0;
};
/*
*/

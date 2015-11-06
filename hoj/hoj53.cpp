#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 10100
#define MOD 910193
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
	//catalon
	ll cat[M],c[M];
	memset(c,0,sizeof(c));
	cat[0]=c[0]=1;	
	for(int i=1;i<M;cat[i]=c[i],++i)
		for(int j=1;j<=i;++j)
			c[j]=(c[j]+c[j-1])%MOD;	
	
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int a;
		scanf("%d",&a);
		printf("%I64d\n",cat[a]);
	};
	return 0;
};
/*
*/

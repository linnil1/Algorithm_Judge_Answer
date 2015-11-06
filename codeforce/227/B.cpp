#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 200100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>



int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	char a[M],b[M];
	while(~scanf("%s%s",a,b))
	#endif	
	{
		int c[1000];		
		memset(c,0,sizeof(c));
		
		int n=0;
		for(int i=0;a[i];++i)
			++c[a[i]];
			
		int ya=0;
		for(int i=0;b[i];++i)
			if(c[b[i]])
				--c[b[i]],++ya,b[i]=-1;
			
		for(int i=0;b[i];++i)
			if(b[i]!=-1)
				if(c[tolower(b[i])])
					++n,--c[tolower(b[i])];
				else if(c[toupper(b[i])])
					++n,--c[toupper(b[i])];
		
		printf("%d %d\n",ya,n);
		
	};
	return 0;
};
/*
*/

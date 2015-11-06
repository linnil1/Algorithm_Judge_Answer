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
		string s[n];
		for(int i=0;i<n;++i)
			std::cin>>s[i];
		std::sort(s,s+n);
		for(int i=n-1;i>=0;--i)
			std::cout<<s[i];
		puts("");
	};
	return 0;
};
/*
*/

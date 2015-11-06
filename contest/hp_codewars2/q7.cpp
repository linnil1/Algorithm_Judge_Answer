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
	char ch1[100],ch2[100];
	while(~scanf("%s%s",ch1,ch2))
	#endif	
	{
		int len = strlen(ch1);
		int a=0,b=0;
		for(int i=0;i<len;++i)
			if(ch1[i]==ch2[i])
				++a;
		for(int i=0;i<len;++i)
			for(int j=0;j<len;++j)
				if(ch1[i]==ch2[j])
					++b;
		printf("%dA%dB\n",a,b-a);
;	};
	return 0;
};
/*
*/

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
	char ch[10];
	int n;
	while(~scanf("%s%d",ch,&n))
	#endif	
	{
		while(n--)
		{
			char tmp[12];
			scanf("%s",tmp);
			for(int i=0;i<5;++i)
				if(tmp[i]=='1')
					std::swap(ch[i],ch[i+1]);
			//printf("%d",n);
		}
		printf("%s\n",ch);
	};
	return 0;
};
/*
*/

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
	char c[10];
	while(~scanf("%s",c))
	#endif	
	{
		bool ch[12];
		for(int i=0;c[i];++i)
			ch[i] = c[i]-'0';
		
		bool a = (!ch[0]) & ch[1],
			c = !(ch[2]&ch[3]);
			
		
		printf("%d%d%d%d\n",a,a|c,c,  (ch[4]|ch[5]) & ( (!ch[6]) | ch[7]) );
	};
	return 0;
};
/*
*/

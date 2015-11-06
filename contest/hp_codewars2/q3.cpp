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
	char ch[15];
	while(~scanf("%s",ch))
	#endif	
	{
		int sum=0;
		for(int i=1;i<8;++i)
			sum += (ch[i]-'0')*i;
		switch(ch[0])
		{
			case 'A':sum+=1;break;
			case 'E':sum+=9;break;
			case 'P':sum+=17;break;
			case 'M':sum+=25;break;
		}
		//printf("%d",sum);
		if(sum%10 == 10 + '0'- ch[8] )
			puts("Success");
		else
			puts("Fail");
	};
	return 0;
};
/*
*/

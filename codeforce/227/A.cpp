#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10000
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
	std::string a,b; 
	while(std::cin>>a>>b)
	#endif	
	{
		++a[a.size()-1];
		int ok=1;
		for(int i=a.size()-1;i>=1&&a[i]>'z';--i)
		{
			a[i]-=26;
			if(i>=1)
				++a[i-1];
		}
		if(a[0]>'z')
			ok=0;
		if(!ok || a>=b)
			puts("No such string");
		else
			std::cout<<a<<"\n";
				
	};
	return 0;
};
/*
*/

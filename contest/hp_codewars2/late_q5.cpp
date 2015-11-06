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
	char c[1000];
	int n;
	while(~scanf("%s%d",c,&n))
	#endif	
	{
		int i;
		for(i=0;c[i]!='.';++i);
		c[i]='\0';
		printf("Success: %s_mod.txt",c);
		
		std::vector<string> hid;
		for(int i=0;i<n;++i)
		{
			string c;
			std::cin>>c;
			hid.pb(c);
		}
		
		string c;		
		std::getline(std::cin,c);
		std::getline(std::cin,c);
		int s=0;
		for(int i=0;i<c.size();++i)
		{
			if(!isalnum(c[i]))
			{
				if(s!=i)
				{
				
					int ifhid=0;
					for(int i=0;i<n;++i)
						if(c.compare(s,hid[i].size(),hid[i])==0 ) 
						{
							ifhid=1;						
							break;
						};
					std::cout << (ifhid? "***":string(c.begin()+s,c.begin()+i));
				}
				putchar(c[i]);
				s=i+1;
			}
		}
		if(s!=c.size())
		{		
			int ifhid=0;
			for(int i=0;i<n;++i)
				if(c.compare(s,hid[i].size(),hid[i])==0 ) 
				{
					ifhid=1;						
					break;
				};
			std::cout << (ifhid? "***":string(c.begin()+s,c.begin()+i));
		}
	
		
	};
	return 0;
};
/*
Sample.txt 1 John
Mary is upset about what John did.
S2.txt 4 HP ProBook performance comprehensive
The sleek HP ProBook 450 with optional 10-point touchscreen and the latest generation technologies delivers powerful performance in the office or on the go. Proven reliability and comprehensive HP security features help keep your data and investment protected.

*/

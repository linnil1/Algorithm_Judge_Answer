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

struct xy
{
	int x,y;
	ll dis;
	char ab;
};
bool operator < (xy a,xy b)
{
	return a.dis<b.dis;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int a,b;
	std::vector<xy> v;
	while(~scanf("%d%d",&a,&b))
	#endif	
	{
		char c[100];
		gets(c);
		//printf("!%s!",c);
		int i;
		for(i=0;c[i];++i)
			if(isalpha(c[i]))
				break;
		
		if(c[i])
			v.pb ( xy{a,b,0,c[i]});
		else
		{
			for(int i=0;i<v.size();++i)
				v[i].dis = (ll)(v[i].x-a)*(v[i].x-a)+ (ll)(v[i].y-b)*(v[i].y-b) ;//,printf("%d%d%c\n",v[i].x,v[i].y,v[i].ab);
			
			std::sort(v.begin(),v.end());
			
			int ca=0,cb=0;
			for(int i=0;i<5;++i)
			{
				if(v[i].ab =='a')
					++ca;
				else
					++cb;
				if(i==2)
					printf("%c",ca>cb?'a':'b');
			 } 
			 printf("%c",ca>cb?'a':'b');
			 v.clear();
			
		}
		
		
		
	};
	return 0;
};
/*
*/

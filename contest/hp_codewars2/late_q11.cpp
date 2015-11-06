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

int win;
#define wl(i) if(c[i]=='O')return win=1;else if(c[i]=='X')return win=-1;
int judge(char *c)
{
	for(int i=0;i<3;++i)
	{	
		if(c[i]==c[i+3] && c[i]==c[i+6])
			wl(i);
		if(c[i]==c[i+1] && c[i]==c[i+2])
			wl(i);
	};
	if(c[0]==c[4] && c[0]==c[8])
		wl(0);
	if(c[2]==c[4] && c[2]==c[6])
		wl(2);
	return 0;
	
}
int dfs(char*c ,int who,int dep)//if i don't missread the question
{
	if(win==1)
		return win;	
	if(!dep)
		return 0;	
	for(int i=0;i<9;++i)
		if(c[i]=='A')
		{
			if(who)
				c[i]='O';
			else
				c[i]='X';
				
			judge(c);
			if(win)
				return win;	
			dfs(c,!who,dep-1);
			if(win==1)
				return win;	
			c[i]='A';
		}
	return 0;
		
};

int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	char c[15];
	while(~scanf("%s",c))
	#endif	
	{
		int co=0,cx=0;
		for(int i=0;i<9;++i)
			if(c[i]=='O')
				++co;
			else if(c[i]=='X')
				++cx;
		win=0;
		if(judge(c)==0)
			dfs(c,co==cx,3+(cx<co));
		puts(win==1 ?"yes":"no");
		
	};
	return 0;
};
/*
AXOAOAXOX
OXOXXAOAO
AOAAXXOOX

*/

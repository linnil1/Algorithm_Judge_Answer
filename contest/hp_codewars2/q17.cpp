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

struct big
{
	int c[15],len;
};

int ctoi (char c)
{
	if( c>='0' && c<='9')
		return c-'0';
	else
		return c-'A'+10;
		
}
void prch(int a)
{
	if(a<=9)
		putchar(a+'0');
	else
		putchar(a-10+'A');
}

bool re( big a)
{
	for(int i=0;i<a.len/2;++i)
		if(a.c[i]!=a.c[a.len-1-i])
			return 0;
	return 1;
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
	char ch[100];
	int n;
	while(~scanf("%s%d",ch,&n))
	#endif	
	{
		big now;
		now.len = strlen(ch);
		for(int i=0;i<now.len;++i)
			now.c[i] = ctoi ( ch[now.len-i-1] );
		int count=0;
		while( !re(now) )
		{			
			++count;
			if(count==11)
				break;
			big tmp ;
			for(int i=0;i<now.len;++i)
				tmp.c[i] = now.c[i] + now.c[ now.len-1-i];
			
			tmp.c[now.len]=0;
			for(int i=0;i<now.len;++i)
			{
				int &a = tmp.c[i];
				if(a>=n)
				{
					tmp.c[i+1]+= a/n;
					a%=n;
				}				
			}
			tmp.len = tmp.c[now.len] ? now.len+1 : now.len ;
			now = tmp;
			//hide
			/*for(int i=now.len-1;i>=0;--i)
				prch(now.c[i]),putchar(' ');
			puts("");*/
			
		}
		if(re(now))
		{
			for(int i=now.len-1;i>=0;--i)
				prch(now.c[i]);
			puts("");
		}
		else
			puts("NONE");
		
	};
	return 0;
};
/*
*/

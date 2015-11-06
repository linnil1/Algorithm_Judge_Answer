#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<algorithm>
char ch[100],ans[500];
int now=0,len,anss;
int tomath()
{
	int sum=0;
	for(;isdigit(ch[now]);++now)
		sum=sum*10+ch[now]-'0';
	//printf("%d!\n",sum);
	--now;
	return sum;
};

void print(int from,int time)
{
	//printf("%d!\n",time);
	if(time==0)
		return ;
	int here=anss;
	
	while(--time)
	{
		for(int i=from;i<here ; ++i)
			ans[anss++]=ans[i];
	};
};
int decode(int from)
{	
	int need=0;
	for(;now<len;++now)
	{
		if(isalpha(ch[now]))
		{				
			from=anss;
			ans[anss++]=ch[now];
		}
		else if(isdigit(ch[now]))
		{			
			print(from,tomath());
		}
		else if(ch[now]=='(')
		{
			from = anss;
			++now ; 
			decode (anss) ;
		}
		else if(ch[now]==')')
			return 0;
	};
};
int main()
{
	int n;
	while(~scanf("%s",ch))
	{
		len=strlen(ch);
		anss=0;
		now=0;
		decode(0);
		ans[anss]='\0';
		puts(ans);
			
	};
	return 0;
};

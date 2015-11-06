#include<cstdio>
#include<algorithm>
#include<ctype.h>

char c[1000];
int find(int now,int here)
{
	int ch[26];
	for(int i=0;i<26;++i)
		ch[i]=0;
	for(int i=now;i<here;i++)
		if(isalpha(c[i]))
			ch[tolower(c[i])-'a']++;
	int ok=0;
	for(int i=0;i<26;++i)
		if(ch[i]>1)
			ok=1;
	if(ok)
	{
		for(int i=now;i<here;i++)
			if(c[i]!=' '||c[i]!='.'||c[i]!=',')
				putchar(c[i]);
		return 1;
	};
	return 0;
};
int main()
{
	while(gets(c))
	{
		int now=0,sum=0, i=1;
		for(i=1;c[i];++i)
			if(c[i]==' '||c[i]=='.'||c[i]==',')
			{
				if(find(now,i))
				{
					sum++;
					putchar(',');
				};
				now=i+1;	
			};
		if(find(now,i))
			sum++;
		 
		printf("%d­Ó\n",sum);
	};
	return 0;
};
/*
The skirt looks good on you.
I don't think so.
*/

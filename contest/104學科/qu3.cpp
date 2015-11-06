#include<cstdio>
#include<algorithm>
#include<ctype.h>

char c[1000];
int ch[26];
int find(int now,int here)
{
	for(int i=now;i<here;i++)
		if(!isalpha(c[i]))
			return 0;
	for(int i=now;i<here;i++)
		if(isalpha(c[i]))
			ch[tolower(c[i])-'a']++;	
	return 1;
};
void findmax()
{
	int max=0;
	for(int i=0;i<26;++i)		
		if(ch[i]>max)
			max=ch[i];
	for(int i=0;i<26;++i)		
		if(ch[i]==max)
			printf("%c %d\n",i+'A',max);
};
int main()
{
	int time;
	while(~scanf("%d\n",&time))
	{
		for(int i=0;i<26;++i)
			ch[i]=0;
		int sum=0,wrong=0;
		while(time--)
		{
			gets(c);
			int now=0, i=1;
			for(i=1;c[i];++i)
				if(c[i]==' ')
				{
					if(find(now,i))
						++sum;
					else 
						++wrong;
					now=i+1;	
				};
			if(find(now,i))
				++sum;
			else 
				++wrong;
		};		
		printf("合法單字%d\n不合法單字 %d\n",sum,wrong);
		findmax();
	};
	return 0;
};
/*
1
An apple a2 day keeps the doctor away
2
To be or not to be
I think therefor I am
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
/*


#include<time.h>
#include<math.h>
#include<stdlib.h>
*/
#include<algorithm>
/*
#include<queue>
#include<string>
#include<iostream>

#include<map>

#include<cstdlib>
using namespace std;
*/

#define times --time||~scanf("%d",&time)
typedef struct sdfgs
{
	char w[100];
	int len;
}word;
word c[1000];
int a;
inline bool operator < (word a,word b)
{
	return a.len<b.len;
}
int stfind(word &com)
{
	int i,j,k,max=-1;
	word stay=com;
	for(k=std::lower_bound(c,c+a,com)-c;k<a;++k)
	{
		for(i=j=0;i<c[k].len&&j<com.len;++i)
		    if(com.w[j]==c[k].w[i])
				++j;
		if(j==com.len)
		{
		    if(c[k].len-com.len>max)
		    {
				if(max==-1)
				{
				    max=c[k].len-com.len;
				    stay=c[k];
				    continue;
				}
			}
			else if(c[k].len-com.len==max)
				stay=com;
			break;
		};
	};
	printf("%s",stay.w);

};
int main()
{
	int i,j,k,time=1;

	a=0;
	while(scanf("%s",c[a].w))
	{
		if(c[a].w[0]=='|')
		    break;
		c[a].len=strlen(c[a].w);
		++a;
	};

	std::sort(c,c+a);
	int b=0;
	char tep;
	word com;
	scanf("%c",&tep);
	while(~scanf("%c",&tep))
	{
		if(isalpha(tep))
		    com.w[b++]=tep;
		else
	    {
			com.w[b]='\0';
			com.len=b;
			if(b)
				stfind(com);
			putchar(tep);
			b=0;
		};
	};
	return 0;
};
/*
or er ar br cr | o e a b t

*/

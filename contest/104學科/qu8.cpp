#include<cstdio>
#include<algorithm>
#include<ctype.h>

char c[1000];
int num[1000];
int find()
{
	int i=0,now=0;
	while(c[i])
	{
		if(isalpha(c[i]) && now==0)
		{
			putchar(' ');
			now=1;
		};
		if(isalpha(c[i]))
			putchar(c[i]);
		if(!isalpha(c[i]))
			now=0;
		++i;
	};
};
int main()
{
	while(gets(c))
	{
		int sum=0;
		for(int i=0;c[i];++i)
			if(isdigit(c[i]))
				num[sum++]=c[i]-'0';
		std::sort(num,num+sum);
		for(int i=sum-1;i>=0;--i)
			printf("%d",num[i]);
		find();
	};
	return 0;
};
/*
No394way28
god34428Job71
*/

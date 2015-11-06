#include<stdio.h>
int to(char c)
{
	switch(c)
	{
		case '#':return 0;
		case '%':return 1;
		case '$':return 2;
		case '&':return 3;
		case '\\':return 4;
		case '~':return 5;
		case '!':return 6;
		case '@':return -1;		
	};
};
int main()
{
	char c[1000];
	while(~scanf("%s",c))
	{
		if(c[0]=='0'&&!c[1])
			break;
		int i,sum=0;
		for(i=0;c[i];++i)
			sum=sum*7+to(c[i]);
		printf("%d\n",sum);
	};

	return 0;
}


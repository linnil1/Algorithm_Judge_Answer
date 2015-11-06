#include<stdio.h>
#include<string.h>
#define M 200 
int main()
{
	int i,j,k;
	char c[M],d[M]; 
	while(~scanf("%s",c))
	{
		int len=strlen(c);
		for(int i=0;i<len/2;i+=2)
			{char t=c[i];c[i]=c[len-1-i];c[len-1-i]=t;} 
		printf("%s\n",c);
	};
	return 0;
};

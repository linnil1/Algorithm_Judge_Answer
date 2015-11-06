#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lld long long int
#define M 200 
int main()
{
	srand(time(NULL));
	int i,j,k;
	char c[M],d[M]; 
	int a; 
	
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%d",&a))
	while(a--)
	{
		int len=rand()%M; 
		for(i=0;i<len;++i)
			c[i]=rand()%26+'A';
		c[i]='\0'; 
		fprintf(fin,"%s\n",c);
		
		for(i=0;i<len/2;i+=2)
			{char t=c[i];c[i]=c[len-1-i];c[len-1-i]=t;} 
		fprintf(fout,"%s\n",c);
	};
	return 0;
};

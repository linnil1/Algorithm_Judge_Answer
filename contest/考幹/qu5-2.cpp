#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lld long long int
#define M 200 
#define m 40 
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
		
		int len=rand()%m; 
		while(!len)
			len=rand()%m; 
		for(i=0;i<len;++i)
			d[i]=rand()%26+'A'; 		
		d[i]='\0'; 
		if(rand()%5) 
			for(i=0;i<M-2;++i) 
				c[i]=d[rand()%len]; 
		else
			for(i=0;i<M-2;++i) 
				c[i]=rand()%26+'A'; 
		c[i]='\0' ; 
		puts("zxc"); 
		
		fprintf(fin,"%s %s\n",c,d);
		
		int sum=0; 
		for(i=0,k=0;c[i];++sum)
		{ 
			for(int j=0;d[j]&&c[i];++j)
				if(c[i]==d[j])
					++i,++k;
			if(!k)
				break;
			else
				k=0; 
		}; 
		if(!c[i]) 
			fprintf(fout,"%d\n",sum);
		else
			fprintf(fout,"impossible\n");
		
	};
	return 0;
};

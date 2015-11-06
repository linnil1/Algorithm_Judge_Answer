#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lld long long int
#define b 6
//b ¬°¼h¼Æ
int main()
{
	int i,j,k;
	int a;
	srand(time(NULL));
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%d",&k))
	while(k--)
	{
		fprintf(fin,"%d\n",a=rand()%100+1);
		int c[b];
		for(i=0;i<b-1;++i)
		    c[i]=rand()%100-50;
		c[i]=0;
		for(j=1;j<a||j<=b;++j)
		{
			if(j<=b)
			    fprintf(fin,"%d ",c[0]);
			if(j==a)
				fprintf(fout,"%d\n",c[0]);
			for(i=0;i<b-2;++i)
			    c[i]+=c[i+1];
		}
		if(j==a)
				fprintf(fout,"%d\n",c[0]);
		fprintf(fin,"\n");
	};
	return 0;
		 
};

#include<stdio.h>
#define lld long long int
lld r=123456789123ll;
lld rand()
{
	return r=541+r*871782911;
};
int main()
{
	lld i,j,k;
	int a,b;
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%I64d",&a))
	{
		while(a--)
		{
			i=rand();
			j=rand();
		    fprintf(fin,"%I64d %I64d\n",i,j);
		    fprintf(fout,"%I64d\n",i+j);
		};
	};
	return 0;
};
/*









*/

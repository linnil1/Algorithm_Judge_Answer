#include<stdio.h>
#define lld long long int
int rand()
{
	static lld r=1234567;
	r=651+r*16769023%1073676287;
	return r-500000000;
};
int main()
{
	int i,j,k;
	int a,b;
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%d",&a))
	{
		while(a--)
		{
		    fprintf(fin,"%d %d\n",i=rand(),j=rand());
		    fprintf(fout,"%d\n",i+j);
		};
	};
	return 0;
};
/*









*/

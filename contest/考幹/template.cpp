#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lld long long int
int main()
{
	int i,j,k;
	int a,b;
	srand(time(NULL));
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%d",&a))
	{
		while(a--)
		{
		    fprintf(fin,"%d\n",rand());
		    
		};
	};
	return 0;
};
/*









*/

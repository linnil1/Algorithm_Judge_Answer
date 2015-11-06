#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lld long long int
struct te
{
	int m,d;
};
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
			te one,two;
			fprintf(fin,"%d ",one.m=rand()%12+1);
		    fprintf(fin,"%d\n",one.d=rand()%month[one.m]);
		    fprintf(fin,"%d ",two.m=rand()%12+1);
		    fprintf(fin,"%d\n",two.d=rand()%month[two.m]);
		    int r=0;
		    if(one.m < two.m ||
			  (one.m == two.m && one.d < two.d)
			  )
		    	r=-1;
			if(r==-1)
			    {te t=one;one=two;two=t;}
			if(one.m == two.m)
			{
				if(one.d == two.d)
					fprintf(fout,"= 0\n");
				else
				    fprintf(fout,"%c %d\n",r?'+':'-',one.d-two.d);
				continue;
			};
			int sum=0;
			sum+=one.d;--one.m;
			sum+=(month[two.m]-two.d);++two.m;

			for(two.m ; two.m <= one.m ; ++two.m)
			    sum+=month[two.m];

			fprintf(fout,"%c %d\n",r?'+':'-',sum);
		};
	};
	return 0;
};
/*









*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lld long long int
struct te
{
	int h,m,s;
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
		    fprintf(fin,"%d %d %d\n",one.h=rand()%24,one.m=rand()%60,one.s=rand()%60);
		    fprintf(fin,"%d %d %d\n",two.h=rand()%24,two.m=rand()%60,two.s=rand()%60);
		    int r=0;
		    if(one.h < two.h ||
			  (one.h == two.h && one.m < two.m)||
			  (one.h == two.h && one.m == two.m && one.s < two.s)
			  )
		    	r=-1;
			if(r==-1)
			    {te t=one;one=two;two=t;}
			one.s-=two.s;
			one.m-=two.m;
			one.h-=two.h;
			if(one.s<0)
			    {one.s+=60;--one.m;};
			if(one.m<0)
			    {one.m+=60;--one.h;};
			if(one.h==0 && one.m ==0 && one.s==0)
			    fprintf(fout,"= 0 0 0\n");
			fprintf(fout,"%c %d %d %d\n",r?'+':'-',one.h,one.m,one.s);
		};
	};
	return 0;
};
/*









*/

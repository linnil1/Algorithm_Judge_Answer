#include<stdio.h>
#define lld long long int
struct te
{
	int m,d;
};
int month[13]={0,31,28,31,30,31,30,31
					  ,31,30,31,30,31};
int main()
{
	int i,j,k;
	int a,b;
	te one,two;
	while(~scanf("%d%d",&one.m,&one.d))
	{
        scanf("%d%d",&two.m,&two.d);
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
				printf("= 0\n");
			else
			    printf("%c %d\n",r?'+':'-',one.d-two.d);
			continue;
		};
		int sum=0;
		sum+=one.d;--one.m;
		sum+=(month[two.m]-two.d);++two.m;
		
		for(two.m ; two.m <= one.m ; ++two.m)
		    sum+=month[two.m];
		
		printf("%c %d\n",r?'+':'-',sum);

	};
	return 0;
};
/*









*/

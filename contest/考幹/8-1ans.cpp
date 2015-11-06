#include<stdio.h>
#define lld long long int
struct te
{
	int h,m,s;
};
int main()
{
	int i,j,k;
	int a,b;
	te one,two;
	while(~scanf("%d%d%d",&one.h,&one.m,&one.s))
	{
        scanf("%d%d%d",&two.h,&two.m,&two.s);
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
		    printf("= 0 0 0\n");
		else
		printf("%c %d %d %d\n",r?'+':'-',one.h,one.m,one.s);
		
	};
	return 0;
};
/*









*/

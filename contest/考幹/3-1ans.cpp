#include<stdio.h>

int main()
{
	int i,j,k;
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		//b=1; 
		for(i=0;i<a;++i,puts(""))
			for(j=0;j<a;++j)
				if(i>=a-b || j<b || j>=a-b)
					putchar('-');
				else
					putchar('X'); 
	};
	return 0;
};
/*









*/

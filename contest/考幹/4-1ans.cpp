#include<stdio.h>
#define lld long long int
int main()
{
	int i,j,k;
	int a,b;
	while(~scanf("%d",&a))
	{
		int bemax=0x88888888,max=0x88888888; 
		while(a--)
		{			
			scanf("%d",&j); 
				if(j > bemax)
					bemax = j ;
				if(bemax > max)
					{int t=max;max=bemax;bemax=t;} 
		};
	    printf("%d %d\n",bemax,max);
	};
	return 0;
};
/*









*/

#include<stdio.h>

int main()
{
	int i,j,k;
	int a,b;
	int x1,x2,y1,y2,x3,y3; 
	while(~scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3))
	{
		if(x1 <= x3 && x3 <= x2 &&
		   y1 <= y3 && y3 <= y2 )		   	 
				printf("Yes\n");
		else
			printf("No\n"); 
	};
	return 0;
};
/*









*/

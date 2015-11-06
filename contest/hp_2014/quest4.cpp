#include<stdio.h>

/*
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
*/

/*
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>

#include<cstdlib>
using namespace std;
*/
#define times --time||~scanf("%d",&time)
int main()
{
	int i,j,k,time=1;
	double a,b;
	char c[100];
	while(~scanf("%s%lf%lf",c,&a,&b))
	{
		if(c[0]=='E'&&c[1]=='N'&&c[2]=='D')
		    break;
		a-=b;
		printf("%s %.2lf ",c,a);
		if     (-0.35<=a&&a<=-0.251)
		    printf("O\n");
		else if(-0.25<=a&&a<=-0.001)
		    printf("B\n");
		else if( 0.00<=a&&a<= 0.249)
		    printf("A\n");
        else if( 0.25<=a&&a<= 0.499)
		    printf("F\n");
        else if( 0.50<=a&&a<= 0.999)
		    printf("G\n");
        else if( 1.00<=a&&a<= 1.499)
		    printf("K\n");
        else if( 1.25<=a&&a<= 2.000)
		    printf("M\n");

		    

	};
	return 0;
};
/*

*/

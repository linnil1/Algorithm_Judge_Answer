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
	int a,c[6];
	for(i=1;i<6;++i)
	    c[i]=0;
	while(~scanf("%d",&a)&&a)
	{
		++c[a];
	};
	int sum=0,peo=0;
	for(i=5;i>0;--i)
	{
	    printf("%d (%2d) |",i,c[i]);
	    for(j=0;j<c[i];++j)
			putchar('=');
		puts("");
		peo+=c[i];
		sum+=c[i]*i;
	};
	printf("Average rating: %.1lf\n",(double)sum/peo);
	return 0;
};
/*
4
5
3
4
2
4
3
5
2
1
3
2
4
3
2
4
3
3
2
4
3
3
5
3
1
4
3
2 4
5
4
3
4
3
3
4
3
0
*/

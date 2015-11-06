#include<stdio.h>
#include<cmath>
int main()
{
	int a,b;
	scanf("%d,%d",&a,&b);
	printf("(0,0),(0,%d),(%d,0)\n",(int)sqrt(b*b-a*a),a);
	return 0;
}


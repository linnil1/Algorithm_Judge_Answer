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
	int a,b;
	char c[1000],change[256],ch[28]=
	{0,
	'A','B','G','D','E',
	'#','Z','Y','H','I',
	'K','L','M','N','X',
	'O','P','Q','R','S',
	'T','U','F','C','$',
	'W','3'};
	int money[28]={0,
	1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900};
	for(i=0;i<28;++i)
	    change[ch[i]]=i;
	while(~scanf("%s",c)&&c[0]!='.')
	{
		int sum=0;
		for(i=0;c[i];++i)
		    sum+=money[change[c[i]]];
		printf("%d\n",sum);

	};
	return 0;
};
/*

*/

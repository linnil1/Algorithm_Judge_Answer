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
	int c[256],ch1[26]={
	1,3,3,2,1,
	4,2,4,1,8,
	5,1,3,1,1,
	3,10,1,1,1,
	1,4,4,8,4,10};
	for(j=0,i='A';i<='Z';++i)
		c[i]=ch1[j++];
	char map[11][11][5];
	while(~scanf("%d",&a))
	{
		for(i=0;i<a;++i)
		    for(j=0;j<a;++j)
		        scanf("%s",map[i][j]);
		scanf("%d",&b);
		char dir[5],name[100];
		int x,y,sum,mult;
		while(b--)
		{
			sum=0;mult=1;
			scanf("%s%d%d%s",name,&x,&y,dir);
			--x;--y;
			if(dir[0]=='V')
			    for(i=x,j=0;name[j];++i,++j)
			        if(map[i][y][1]=='L')
			            sum+=(map[i][y][0]-'0')*c[name[j]];
					else if(map[i][y][1]=='W')
					{
			            mult*=(map[i][y][0]-'0');
			            sum+=c[name[j]];
					}
					else sum+=c[name[j]];
			else
			    for(i=y,j=0;name[j];++i,++j)
			        if(map[x][i][1]=='L')
			            sum+=(map[x][i][0]-'0')*c[name[j]];
					else if(map[x][i][1]=='W')
					{
			            mult*=(map[x][i][0]-'0');
			            sum+=c[name[j]];
					}
					else sum+=c[name[j]];
			printf("%s %d\n",name,mult*sum);
		};

	};
	return 0;
};
/*

*/

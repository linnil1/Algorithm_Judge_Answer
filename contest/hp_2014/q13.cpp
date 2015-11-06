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
#include<string>
#include<iostream>
#include<algorithm>
#include<map>

#include<cstdlib>
using namespace std;
*/

#define times --time||~scanf("%d",&time)
char r[4][5];
int bj[4]={0x44C0,0x8E00,0xC880,0xE200},
    bt[4]={0xE400,0x4c40,0x4E00,0x8C80},
    bl[4]={0x88C0,0xE800,0xC440,0x2E00},
    bz[2]={0xC600,0x4C80},
	bs[2]={0x6C00,0x8C40},
	bi[2]={0x8800,0xC000},
	chan=0x1111,
	c[50],a;
void draw(int a,char c)
{
	int i,j;
	for(i=3;i>=0;--i)
	    for(j=3;j>=0;--j,a>>=1)
			if(a&1)
			    r[i][j]=c;
};
int dfs(int now,int room)
{
	if(now==a)
	    return 1;
	int i,j;
	for(i=c[now];;)
	{
		for(j=i;;)
		{
			if((j&room)==j)
			    if(dfs(now+1,room^j))
			    {
			        draw(j,now+'A');
			        return 1;
				};
			
			if(j&15)
			    break;
			else
			    j>>=4;
		};
		if(i&chan)
		    break;
		else
		    i>>=1;
	};
	return 0;
};
int main()
{
	int i,j,k,time=1;
	
	char tep[5];
	while(~scanf("%d",&a))
	{
		for(i=0;i<a;++i)
		{
		    scanf("%s",tep);
		    switch(tep[0])
		    {
				case 'J':c[i]=bj[tep[1]-'1'];break;
				case 'T':c[i]=bt[tep[1]-'1'];break;
				case 'L':c[i]=bl[tep[1]-'1'];break;
				case 'Z':c[i]=bz[tep[1]-'1'];break;
				case 'S':c[i]=bs[tep[1]-'1'];break;
				case 'I':c[i]=bi[tep[1]-'1'];break;
			};
		};
		int room=0xffff;
		dfs(0,room);
		for(i=0;i<4;++i)
		{
			r[i][4]='\0';
			printf("%s\n",r[i]);
		};
	};
	return 0;
};
/*

5 T1 T3 J3 I1 I2
4 L1 T1 Z1 T2



*/

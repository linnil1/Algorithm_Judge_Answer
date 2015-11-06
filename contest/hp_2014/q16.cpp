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
#define m 10
int c[m][m],h[m],v[m],a,b;
struct sf
{
	int time[m],times,all;
	char dir;
}imp[100];
void pr()
{
	int i,j;
	for(i=0;i<a;++i,puts(""))
    for(j=0;j<a;++j)
    printf("%d ",c[i][j]);
};
int dfs(int);
int permu(int layer,int all,int now,int dir)
{

    if(all>imp[now].all)
	    return 0;
	if(layer==imp[now].times)
	    if(all==imp[now].all)
	        return dfs(now+1);
		else
		    return 0;
	int i,j,x=imp[now].time[layer]/a,k,r,
	        y=imp[now].time[layer]%a;
	for(i=1,j=1<<1;i<=a;++i,j<<=1)
	    if(h[y]&j && v[x]&j)
	    {
	        h[y]^=j;v[x]^=j;
	        if(dir)
	            k=all+i;
			else
			    k=all*i;
			if(!c[x][y])
				c[x][y]=i,r=1;
			else if(i==c[x][y])
				c[x][y]=i,r=0;
			else
			    continue;
			if(permu(layer+1,k,now,dir))
			    return 1;
			if(r)
				c[x][y]=0;
	        h[y]^=j;v[x]^=j;
		};
	return 0;

};
int pair (int now,int dir)
{
	int x1=imp[now].time[0]/a,
	    x2=imp[now].time[1]/a,
	    y1=imp[now].time[0]%a,
	    y2=imp[now].time[1]%a,
	    i,j,k,o,n,r;
	    
	i=dir?1+imp[now].all:imp[now].all;
	
	for(j=1,o=1<<i,n=1<<j ; i<=a ;
	++j,i+=(dir?1:imp[now].all),o=1<<i,n=1<<j)
	
		if(v[x1]&o && h[y1]&o)
		{
			v[x1]^=o;h[y1]^=o;
			
			if(!c[x1][y1])
				c[x1][y1]=i,r=1;
			else if(i==c[x1][y1])
				c[x1][y1]=i,r=0;
			else
			    continue;
			    
			if(v[x2]&n && h[y2]&n)
			{
				v[x2]^=n;h[y2]^=n;
				
				if(!c[x2][y2])
					c[x2][y2]=i,r=1;
				else if(i==c[x2][y2])
					c[x2][y2]=i,r=0;
				else
				    continue;
				c[x2][y2]=j;
				if(dfs(now+1))
				    return 1;
				if(r)
				    c[x2][y2]=0;
				v[x2]^=n;h[y2]^=n;
			};
			if(r)
				c[x1][y1]=0;
			v[x1]^=o;h[y1]^=o;
		};
		/*¤Ï*/
    x2=imp[now].time[0]/a,
    x1=imp[now].time[1]/a,
    y2=imp[now].time[0]%a,
    y1=imp[now].time[1]%a,
    i=dir?1+imp[now].all:imp[now].all;

	for(j=1,o=1<<i,n=1<<j ; i<=a ;
	++j,i+=(dir?1:imp[now].all),o=1<<i,n=1<<j)

		if(v[x1]&o && h[y1]&o)
		{
			v[x1]^=o;h[y1]^=o;

			if(!c[x1][y1])
				c[x1][y1]=i,r=1;
			else if(i==c[x1][y1])
				c[x1][y1]=i,r=0;
			else
			    continue;

			if(v[x2]&n && h[y2]&n)
			{
				v[x2]^=n;h[y2]^=n;

				if(!c[x2][y2])
					c[x2][y2]=i,r=1;
				else if(i==c[x2][y2])
					c[x2][y2]=i,r=0;
				else
				    continue;
				c[x2][y2]=j;
				if(dfs(now+1))
				    return 1;
				if(r)
				    c[x2][y2]=0;
				v[x2]^=n;h[y2]^=n;
			};
			if(r)
				c[x1][y1]=0;
			v[x1]^=o;h[y1]^=o;
		};
	return 0;

};
int dfs(int now)
{
	if(now==b)
	    return 1;
	switch(imp[now].dir)
	{
		case '+':return permu(0,0,now,1);
        case '-':return pair(now,1);
        case 'x':return permu(0,1,now,0);
        case '/':return pair(now,0);
	};

};
int main()
{
	int i,j,k,time=1;
	char tep[m];
	while(~scanf("%d%d",&a,&b))
	{
		for(i=0;i<a;++i)
		{
		    for(j=0;j<a;++j)
		        c[i][j]=0;
			h[i]=-1;
			v[i]=-1;
		};
		for(i=0;i<b;++i)
		{
		    scanf("%d%s%d",&imp[i].all,tep,&imp[i].times);
		    for(j=0;j<imp[i].times;++j)
		    {
		        scanf("%d",&imp[i].time[j]);
				--imp[i].time[j];
			}
			imp[i].dir=tep[0];
		};
		dfs(0);
		pr();

	};
	return 0;
};
/*
3 4
2 x 2 1 4
3 / 2 2 3
7 + 3 5 6 9
2 - 2 7 8
*/

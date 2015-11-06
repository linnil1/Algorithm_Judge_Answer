#include<stdio.h>
#include<math.h>
/*
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>


*/
#include<algorithm>
#include<queue>
/*
#include<iostream>

#include<string>

using namespace std;
*/
#define times --time||~scanf("%d",&time)
long long int c[1010][1010];
long long int d[1010];
typedef struct fa
{
	long long int x,y;
}xy;
xy po[1010];

int main()
{
    int q,w,e,r,t,a,time=1;
    long long int max,min;
    while(times)
    {
        ~scanf("%d",&a);
        char vis[a];
		for(q=0;q<a;++q)
		    scanf("%I64d%I64d",&po[q].x,&po[q].y);
		for(q=0;q<a;++q)
		    for(w=0;w<a;++w)
		        c[q][w]=(po[q].x-po[w].x)*(po[q].x-po[w].x)
				       +(po[q].y-po[w].y)*(po[q].y-po[w].y);
		for(q=0;q<a;++q)
		{
		    vis[q]=1;
		    d[q]=0x7fffffffffffffffll;
		};
		d[0]=0;
		for(t=0;t<a;++t)
		{
			r=-1;min=0x7fffffffffffffffll;
			for(q=0;q<a;++q)
			    if(vis[q]&&min>d[q])
			    {
					min=d[q];
					r=q;
				};
			if(r==-1)
			    break;
			vis[r]=0;
			for(q=0;q<a;++q)
			    if(vis[q]&&d[q]>c[r][q])
					d[q]=c[r][q];
		};
		max=d[1];
		for(q=2;q<a;++q)
		    if(max<d[q])
		        max=d[q];
		printf("%I64d\n",(long long int)(ceil((sqrt(max))/2)));
    }
    return 0;
};
/*
*/






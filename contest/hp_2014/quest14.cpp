#include<stdio.h>

/*
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
*/
#include<queue>
/*

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
	char tep[100],ta[5];
	char map[100][100];
	while(~scanf("%d",&a))
	{
		for(i=0;i<100;i++)
		    for(j=0;j<100;++j)
		        map[i][j]=0;
		b=0;
		while(a--)
		{
			scanf("%s",ta);
			for(i=0;i<b;++i)
			    if(tep[i]==ta[0])
			        break;
			if(i==b)
			    tep[b++]=ta[0];
			scanf("%s%d",ta,&k);
			for(j=0;j<b;++j)
			    if(tep[j]==ta[0])
			        break;
			if(j==b)
			    tep[b++]=ta[0];
			map[i][j]=map[j][i]=k;
		};
		/*for(i=0;i<b;i++,puts(""))
		    for(j=0;j<b;++j)
		        printf("%d ",map[i][j]);*/
		
		int start,end;
		scanf("%s",ta);
		for(i=0;i<b;++i)
		    if(tep[i]==ta[0])
		        break;
		start=i;
		scanf("%s",ta);
		for(i=0;i<b;++i)
		    if(tep[i]==ta[0])
		        break;
		end=i;
		int vis[b],use[b];
		for(i=0;i<b;++i)
		    vis[i]=0x7fffffff,
		    use[i]=0;
		    
		use[start]=1;
		vis[start]=0;
		std::queue<int> qu;
		qu.push(start);
		while(!qu.empty())
		{
			k=qu.front();
			qu.pop();
			if(k==end)
			    continue;
			if(!use[k])
			    continue;
			use[k]=0;
			for(i=0;i<b;++i)
			    if(map[k][i]&&map[k][i]+vis[k]<=vis[i])
			    {
					vis[i]=map[k][i]+vis[k];
					qu.push(i);
					use[i]=1;
				};
		};
		if(vis[end]==0x7fffffff)
		    puts("NoRoute");
		else
		    printf("%d\n",vis[end]);
	};
	return 0;
};
/*

*/

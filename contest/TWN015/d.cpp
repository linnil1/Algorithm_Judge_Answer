#include<stdio.h>
#include<algorithm>
struct food
{
	int cost,get;
};
int max,a,vis[20];
inline bool scmp(food a,food b)
{
	return a.cost>b.cost;
};
food c[20],f;
int big(int,int);
int small(int all,int money)
{
	//printf("%d %d\n",all,money);
	int q,e,r=0,smaller=0x7fffffff;
	f.cost=money;
	for(q=std::lower_bound(c,c+a,f,scmp)-c;q<a;++q)
		if(vis[q])
		{
			r=1;
			vis[q]=0;
			e=big(all,money);
			if(e<smaller)
				smaller=e;
			vis[q]=1;
		};
	if(r)
		return smaller;
	else
		return all;
};
int big(int all,int money )
{
	//printf("%d %d\n",all,money);
	int q,e,r=0,bigger=0;
	f.cost=money;
	for(q=std::lower_bound(c,c+a,f,scmp)-c;q<a;++q)
		if(vis[q])
		{
			r=1;
			vis[q]=0;
			e=small(all+c[q].get,money-c[q].cost);
			if(e>bigger)
				bigger=e;
			vis[q]=1;
		};
	if(r)
		return bigger;
	else 
		return all;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int q,w,e,r,t,b,time=1;
	while(~scanf("%d",&time))
	while(time--)
	{
		scanf("%d",&a);
		int money;
		for(q=0;q<a;++q)
			scanf("%d%d",&c[q].get,&c[q].cost);
		std::sort(c,c+a,scmp);
		scanf("%d",&money);
		for(q=0;q<=a;++q)
			vis[q]=1;
		f.get=0x7fffffff;
		printf("%d\n",big(0,money));
	};
	return 0;
};
/*
3
5 
7 7 
5 5 
4 4 
3 3 
2 2 
9
5 
8 6 
5 5 
5 5 
4 4 
2 2 
9 
5 
8 6 
5 5 
5 5 
4 4 
2 2 
22 
*/

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#define lld long long int
struct ele
{
	int w,s,num,from,big;
}c[1010];
bool operator < (ele a,ele b)
{
	if(a.w!=b.w)
		return a.w<b.w;
	return a.s>b.s;
};
int a;
void todp()
{
	for(int i=0;i<a;++i)
	{
		ele &e = c[i];
		e.big = 1 ;
		e.from = -1;
		
		for(int j=i-1;j>=0;--j)
			if( c[j].w < e.w && c[j].s > e.s && c[j].big + 1 > e.big )
			{
				 e.big = c[j].big + 1 ;
				 e.from = j ;
			}	
		//printf("%d %d %d\n",e.big,e.from,c[e.from] < e);	
	};
};
void prdp()
{
	int max=0,num;
	for(int i=0;i<a;++i)
		if(c[i].big > max)
		{
			max = c[i].big ;
			num = i  ;
		};
	printf("%d\n",max);
	
	int stack[max],now=0;
	while(num!=-1)
	{
		stack[now++]=c[num].num;
		num=c[num].from;
	};
	while(now--)
		printf("%d\n",stack[now]);
};
bool input(int &i)
{
	if(scanf("%d%d",&c[i].w,&c[i].s)!=2)
		return 0;
	c[i].num=i+1;
	++i;
	return 1;
};

int main()
{
	int time=100,i=0;
	//freopen("textin.txt","r",stdin);
	//freopen("textout.txt","w",stdout);
	while(
		//--time || ~scanf("%d",&time) 
		//~scanf("%d",&a)
		input(i)
		 )
	{	
			
						
		
		
	};
	a=i;
	std::sort(c,c+a);		
	todp();
	prdp();
	scanf("%*d");
	return 0;
};
/*
9
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
*/

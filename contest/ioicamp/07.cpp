#include<cstdio>
#include<algorithm>
#include<cstring>
//#include<ctype.h>
//#include<cmath>
//#include<stack>
#define lld long long int
#define M 5000
char ch[M];
int order[M],len,num[M],temp[M],where;

bool mycomp(int a,int b)
{
	if(order[a]!=order[b])
		return order[a] < order[b];
	else
		return order[(a+where)%len] < order[(b+where)%len]; 
};
void print()
{
/*	for(int i=0;i<len;++i)
		printf("%d ",temp[i]);
	puts("!!");*/
	for(int i=0;i<len;++i)
		printf("%d ",order[i]);
	puts("??");
	
};
int main()
{
	int count;
	while(~scanf("%d",&count))
	while(count--){
		scanf("%s",ch);
		
		//init
		len = strlen(ch) ;
		for(int i=0;i<len;++i)
			num[i]=i,
			order[i]=ch[i];
			
		for(int i=len;i<M;++i)
			ch[i]=order[i]=0;
			
		//log n
		int all=0;
		for(all=0;(1<<all) < len;++all);
		//printf("%d %d!!\n",len,1<<all);
		//print();
		for(int i=0;i<=all;++i)
		{
			where = (1<<i);
			//sort
			std::sort(num,num+len,mycomp);
			
			//toorder
			for(int i=0;i<len;++i)
				temp[i] = order[i] *M +order[(i+where)%len];
			for(int i=0,now=-1,sum=-1;i<len;++i)
				if(temp[num[i]] != now)
				{
					now = temp[num[i]] ;
					order[num[i]]=++sum;
				}
				else
					order[num[i]]=sum;
			//print();
		};		
		//getmax
		int min=M,m;
		for(int i=0;i<len;++i)
			if(order[i] < min)
				min = order[i],
				m = i;
		printf("%d\n",m);		
	};
	return 0;
};
/*
2
abcaa
mississippi

01200
12300
12340
12340
*/


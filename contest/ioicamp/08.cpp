#include<cstdio>
#include<algorithm>
#include<cstring>
//#include<ctype.h>
//#include<cmath>
//#include<stack>
#define lld long long int
#define M 5000
char ch[M];
int order[M],ori[M],len,num[M],temp[M],where;

int next(int a)
{
	if(a+where*2-1 >=len)
		return ori[a+1];
	else
		return order[(a+1)%len]; 
};

bool mycomp(int a,int b)
{
	if(order[a]!=order[b])
		return order[a] < order[b];
	else
		return next(a) < next(b); 
};
bool myori(int a,int b)
{
	if(ori[a]!=ori[b])
		return ori[a] < ori[b];
	else
		return ori[a+1] < ori[b+1];
};
void print()
{
	for(int i=0;i<len;++i)
		printf("%d ",ori[i]);
	puts("");
	for(int i=0;i<len;++i)
		printf("%d ",order[i]);
	puts("");
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
			ori[i]=order[i]=ch[i];
			
		for(int i=len;i<M;++i)
			ori[i]=ch[i]=0;//order[i]=0;
			
		//log n
		int all=0;
		for(all=0;(1<<all) < len;++all);
		for(int i=0;i<=all;++i)
		{
			print();
			//sort
			where = 1 << i ;
			std::sort(num,num+len,mycomp);
			//toorder
			for(int i=0;i<len;++i)
				temp[i] = order[i] *M + next(i);
			for(int i=0,now=-1,sum=0;i<len;++i)
				if(temp[i] != now)
				{
					now = temp[i] ;
					order[num[i]]=++sum;
				}
				else
					order[num[i]]=sum;
			//ori
			std::sort(num,num+len,myori);
			for(int i=0;i<len;++i)
				temp[i] = ori[i] *M +ori[i+1];
			for(int i=0,now=-1,sum=0;i<len;++i)
				if(temp[i] != now)
				{
					now = temp[i] ;
					ori[num[i]]=++sum;
				}
				else
					ori[num[i]]=sum;
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


#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#define lld long long int
lld map[15][115];
int a,b;
int from[15][115];
inline int find(int t)
{
	if(t<0)
		return a-1;
	if(t>=a)
		return 0;
	else
		return t;
};

int ans[115];
int dfs(int i,int j)
{
	if(j==0)
	{
		if(i==ans[j])
			return 0;
		else if(i<ans[j])
		{
			ans[j]=i;
			return 1;
		}
		else
			return -1;
	};
	int t=dfs(from[i][j],j-1);
	if(t>0)
	{
		ans[j]=i;
		return 1;
	}
	else if(t==0)
		if(i==ans[j])
			return 0;
		else if(i<ans[j])
		{
			ans[j]=i;
			return 1;
		}
		else
			return -1;
	else
		return t;
};
int findmin(int x,int y)
{
	lld sum[3];
	int num[3];
	for(int i=0;i<3;++i)
	{	
		num[i]=find(x-1+i);
		sum[i]=map[num[i]][y-1];
	};
	
	for(int i=1;i<3;++i)
		if(sum[i]<sum[0])
		{
			sum[0]=sum[i];
			num[0]=num[i];
		}
		else if(sum[i]==sum[0])
		{
			for(int i=0;i<y;++i)
				ans[i]=999;
			dfs(num[0],y-1);	
			num[0]=dfs(num[i],y-1) >0 ? num[i] : num[0] ;
		};
	map[x][y]+=sum[0];
	return num[0];
}
void findminpr()
{
	lld min=map[0][b-1];
	for(int i=1;i<a;++i)
		min=std::min(map[i][b-1],min);
	
	
	for(int i=0;i<b;++i)
		ans[i]=999;
	for(int i=0;i<a;++i)
		if(map[i][b-1]==min)
			dfs(i,b-1);
	/*for(int i=0;i<a;++i,puts(""))		
		for(int j=0;j<b;++j)
			printf("%d ",from[i][j]);*/
	for(int i=0;i<b;++i)	
		printf("%d ",ans[i]+1);		
	printf("\n%lld\n",min);
	
};
int main()
{
	int time=100;
	//freopen("textin.txt","r",stdin);
	//freopen("textout.txt","w",stdout);
	while(
		//--time || ~scanf("%d",&time) 
		~scanf("%d%d",&a,&b)
		 )
	{	
		for(int i=0;i<a;++i)
			for(int j=0;j<b;++j)
				scanf("%lld",map[i]+j);
						
		for(int j=1;j<b;++j)
			for(int i=0;i<a;++i)
				from[i][j]=findmin(i,j);
		
		findminpr();
	};
	return 0;
};
/*
100
3
25 50 75
10
4
4 5 7 8

*/

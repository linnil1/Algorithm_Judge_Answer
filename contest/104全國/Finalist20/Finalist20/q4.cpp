#include<cstdio>
#include<algorithm>
#include<queue>
#define M 2147483647
int road[10100][10100];
int val[10100];
int n;

int bfs(int t)
{
	std::queue<int > q;
	q.push(t);
	for(int i=0;i<n;++i)
		val[i]=M;
			
	val[t]=0;
	while(q.size())
	{
		int now = q.front();
		q.pop();
		for(int i=0;i<n;++i)
			if(road[now][i] !=M && val[now]+road[now][i] < val[ i ])
			{
				val[i] = val[now]+road[now][i] ;
				q.push(i);
			};
	};
	int max = 0 ;
	for(int i=0;i<n;++i)
		if(val[i] > max)
			max =val[i];
	return max ;
	
};
int findori()
{
	for(int i=0;i<n;++i)
	{
		int tot=0;
		for(int j=0;j<n;++j)
			if(road[i][j] != M)
				++tot;
		if(tot==1)
			return i;		
	};	
	
};
int next(int k,int no)
{
	for(int i=0;i<n;++i)
		if(road[k][i]!=M && i!=no)
			return i;
	return 0;
};
int main()
{
	int time,l;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&l);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				road[i][j]=M;
		
				
		if(n==1)
		{
			puts("0");
			continue;
		}
			
		//int sum=0;
		for(int i=1;i<n;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			road[a][b]=road[b][a]=c;
		};
		
		/*for(int i=0;i<n;++i)
		{
			int sum=0;
			for(int j=0;j<n;++j)
				if(road[i][j] != M)
					++sum;
			if(sum==1)
				val[i]=0;
			bfs(i);
		};
		int max = 0 ;
		for(int i=0;i<n;++i)
			if(val[i] > max)
				max =val[i];*/
		/*int min =M;
		for(int i=0;i<n;++i)
		{
			int t=bfs(i);
			if(t < min)
				min =t;
		}*/
		int s=findori(),
		s1 = next(s,-1);
		
		int sum[n];
		sum[0]=0;
		for(int i=1;i<n;++i)
		{
			//printf("%d\n",s);
			
			sum[i] = sum[i-1] + road[s][s1];
			//printf("%d %d\n",s,s1);
			int t=s;
			s=s1;
			s1=next(s,t);
		};
		int a,min=M;
		
		a=0;
		for(int i=0;i<n;++i)
		{
			for(;a<n && sum[a]-sum[i] <= l;++a);
			--a;
			
			int all = std::max(sum[i]-sum[0] , sum[n-1]-sum[a]);
		//	printf("%d %d %d %d\n",sum[i],sum[0] , sum[n-1],sum[a]);
			if(all < min)
				min = all ;				
			
		};		
		
		printf("%d\n",min);
	};
	return 0;
};

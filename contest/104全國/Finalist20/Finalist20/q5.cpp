#include<cstdio>
#include<algorithm>


int f[20100],group;

int find(int a)
{		
	//puts("zxc");
	return f[a] == a ? a : (f[a] = find(f[a]));
};
void tofa(int a,int b)
{
	group--;
	f[find(a)] = find(b);
};

bool isnosame(int a,int b)
{
	return find(a) != find(b);
};
struct road
{
	int x,y ,cost;
	friend bool operator < (road a,road b)
	{
		return a.cost < b.cost ;
	};
}r[20100];

int solve(int n,int m)
{
	int sum=0,i;
	for(i=0;i<m && group > 2 ;++i)
	{
		if(isnosame(r[i].x , r[i].y))
		{
			tofa(r[i].x , r[i].y);
			

			//sum+=c[i].cost;
		};
	};
	int time=0;
	for(;i<m && time <2 ;++i)
	{
		if(isnosame(r[i].x,r[i].y))
		{
			if(time == 0)
			{
				sum = r[i].cost;
				++time;
			}
			else
			{
				sum = r[i].cost - sum;
				++time;
			};
		};
	};
	
	return sum;
};

int main()
{
	int n,m,time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		group = n ;
		for(int i=0;i<n;++i)
			f[i]=i;
		
		for(int i=0;i<m;++i)
			scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].cost);
			
		std::sort(r,r+m);
		//puts("zxc");
		printf("%d\n",solve(n,m));
	};
	return 0;
};

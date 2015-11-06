#include<cstdio>
struct cube
{
	int face[6],
		max[6],
		fanum[6],faface[6];
};
void dp(cube *c,int a,int f)
{
	for(int i=0;i<a;++i)
		for(int j=0;j<6;++j)
			if(c[a].face[f]==c[i].face[j] && c[i].max[j^1]+1 > c[a].max[f])
			{
				c[a].fanum[f] = i;
				c[a].faface[f] = j;
				c[a].max[f] = c[i].max[j^1]+1  ;
			};
};
char name[6][10]={"front","back","left","right","top","bottom"};
void out(cube *c,int a,int f)
{
	if(c[a].fanum[f]!=-1)
		out(c,c[a].fanum[f],c[a].faface[f]^1);
//	printf("%d %s %d%d\n",a+1,name[f],c[a].face[f],c[a].face[f^1]);
	printf("%d %s\n",a+1,name[f]);
};
int main()
{
	int n,count=1;
	while(~scanf("%d",&n)&&n)
	{
		//in
		cube c[n];
		for(int i=0;i<n;++i)
			for(int j=0;j<6;++j)
			{
				scanf("%d",&c[i].face[j]);
				c[i].max[j]=1;
				c[i].fanum[j]=-1;
			};
		//dp
		for(int i=0;i<n;++i)
			for(int j=0;j<6;++j)
				dp(c,i,j);
		//out
		int max=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<6;++j)
				if( c[i].max[j] > max)
					max = c[i].max[j];
		for(int i=n-1;max;--i)
			for(int j=0;j<6&&max;++j)
				if(max==c[i].max[j])
				{
					if(count!=1)
						puts("");
					printf("Case #%d\n%d\n",count++,max);
					out(c,i,j);
					max=0;
				};
		
	};
	return 0;
};

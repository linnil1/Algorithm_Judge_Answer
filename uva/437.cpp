#include<cstdio>
#include<algorithm>
struct box
{
	int r[3];
};
bool operator < (box a,box b)
{
	if(a.r[0] != b.r[0])
		return a.r[0] > b.r[0];
	else
		return a.r[1] > b.r[1];
};
int main()
{
	int n,num=1;
	while(~scanf("%d",&n)&&n)
	{
		box c[n*3];
		for(int i=0;i<n;++i)			
		{
			box *b=&c[i*3];
			scanf("%d%d%d",& b -> r[0] ,& b -> r[1] ,& b -> r[2] );
			std::sort( b -> r , b -> r +3);
			(b+1)-> r[0] = b -> r[0];
			(b+1)-> r[1] = b -> r[2];
			(b+1)-> r[2] = b -> r[1];
			(b+2)-> r[0] = b -> r[1];
			(b+2)-> r[1] = b -> r[2];
			(b+2)-> r[2] = b -> r[0];			
		};
		n=n*3;
		std::sort(c,c+n);
		int themax=0;
		for(int i=0;i<n;++i)
		{
			int max=0;
			for(int j=i-1;j>=0;--j)
				if(c[i].r[0] < c[j].r[0] && c[i].r[1] < c[j].r[1] && c[j].r[2] > max)
					max = c[j].r[2];
			c[i].r[2] += max;
			if(c[i].r[2] > themax)
				themax= c[i].r[2];
		};		
		printf("Case %d: maximum height = %d\n",num++,themax);		
	};
	return 0;
};

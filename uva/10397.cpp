//#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
//using namespace std;

struct road
{
	int x,y;
	double val;
};

bool operator < (road a,road b)
{
	return a.val < b.val ;
};

int s[1000],group;
road r[1000];
void init(int n)
{
	for(int i=0;i<n;++i)
		s[i]=i;
	group = n;
};
int find(int a)
{
	return s[a] == a ? a : ( s[a] = find( s[a] ) );
};

void uni(int a,int  b)
{
	if(find(a) != find(b))
	{
		s[find(a)]=find(b);
		--group;
	};
	
};

double dis (int x,int y)
{
	road a=r[x],b=r[y]; 
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
};


int main()
{   
	int N;
    while(~scanf("%d",&N))
	{  	   
	   for(int i=0;i<N;++i)
	   		scanf("%d%d",&r[i].x,&r[i].y);
		
		init(N);
		
	   	int M;
	   	scanf("%d",&M);
	   	while(M--)
	   	{
	   		int x,y;
	   		scanf("%d%d",&x,&y);
	   		uni(x-1,y-1);
	   	};
	   	std::vector<road> v;
	   	
	   	for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j)
				if(find(i) != find(j))
				{
					road t;
					t.x=i;
					t.y=j;
					t.val=dis(i,j);
					//printf("%lf\n",t.val);
					v.push_back(t);
				};
		int ok=0;
		double sum=0;
		std::sort(v.begin(),v.end());
		for(int i=0;i<v.size();++i)
		{
			road &t=v[i];
			if(find(t.x) != find(t.y))
			{
				//printf("%d %d %lf\n",t.x,t.y,t.val);
				uni(t.x,t.y);
				sum += t.val ;
			};
			if(group==1)
				break;	
		};
		printf("%.2lf\n",sum);	   	
	}
	return 0;
}


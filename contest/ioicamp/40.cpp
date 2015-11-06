#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#define M 1000000
#define lld long long int 

struct road
{
	int val,from,to;
	
};
bool operator < (road a,road b){return a.val<b.val;};
int d[10100],group;

void init(int m)
{
	group=m;
	for(int i=1;i<=m;++i)
		d[i] = i ;
		
};

int find(int a)
{
	return a==d[a] ? a : ( d[a] = find(d[a])) ;
};

void unin(int a,int b)
{
	if(find(a) != find(b))
	{
		--group;
		d[find(a)] = find(b);
	}
};

int tur(road* r,int m)
{
	int now=0;
	std::sort(r,r+m);
	for(int i=0;i<m && group>1;++i)
	{
		unin( r[i].from , r[i].to );
		now = r[i].val;
	};
	if(group == 1)
		return now;
	else
		return -1;
		
};

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int n , m ;
		scanf("%d%d",&n,&m);
		
		
		init(n);
		
		road r[m];
		for(int i=0;i<m;++i)
			scanf("%d%d%d",&r[i].from,&r[i].to,&r[i].val);
			
		int ans = tur(r,m) ;
		if(ans == -1)
			puts("Earth Worm QAQ");
		else
			printf("%d\n",ans);
		
	}
    return 0;
}

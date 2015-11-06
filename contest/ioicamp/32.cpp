#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#define M 1000000
#define lld long long int 
int prim[100000],prs;

void init()
{
	char g[M+1];
	memset(g,0,sizeof(g));
	prs=0;
	for(int i=2;i<=M;++i)
	{
		if(g[i]==0)prim[prs++]=i;
		for(int j=0;j<prs && i*prim[j]<=M ;++j)
		{
			g[i*prim[j]] = 1;
			if(i%prim[j] == 0) break;
		}
	};
	//printf("%d %lf\n",prs,(double)clock());
};
int find(lld a,lld b)
{
	int num = b-a +1 ;
	char c[num];
	memset(c,0,sizeof(c));
	
	for(int i=0;i<prs;++i)
	{
		int j= (prim[i] - a % prim[i] )%prim[i];
		while (a+j <= prim[i] )
			j+=prim[i];
		for(j ; j<num  ; j+=prim[i])
			c[j] = 1;
		//printf("%d ",j);
		
	};
	int sum=0;
	for(int i=0;i<num;++i)
		if(!c[i])
			++sum;
	return sum - (a == 1);
};
	

int main(){
    int T;
    init();
    scanf("%d",&T);
    while(T--)
	{
		lld a,b;
        scanf("%lld%lld",&a,&b);
        if(a>b)
        	std::swap(a,b);        	
        
        printf("%d\n",find(a,b));
        
        
        
    }
    return 0;
}

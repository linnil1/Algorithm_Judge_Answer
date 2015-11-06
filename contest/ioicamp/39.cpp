#include<bits/stdc++.h>
#define M 1000000
#define lld long long int 


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


int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int n , m ;
		scanf("%d%d",&n,&m);
		
		
		init(n);
		
		for(int i=0,a,b;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			unin(a,b);
		};
			
		if(group==1 && n!=1)
			puts("Chen Li Bang Bang");
		else
			puts("Chen Li Huai Huai");
		
	}
    return 0;
}

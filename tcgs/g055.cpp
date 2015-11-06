#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 10000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

struct xy
{
	int x,y,r;
};
int min;

void dfs(int *arr,int now,int time,int oth)
{
	if(!oth)
	{
		if(time<min)
			min = time;
		return ;
	}
	if(now<0)
		return ;
	dfs(arr,now-1,time+1,(oth|arr[now])^arr[now]);
	dfs(arr,now-1,time,oth);
}

bool touch(ll a,ll b,ll c)
{
	return a*a+b*b <= c*c;
}

int main()
{
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int m,n;
		scanf("%d%d",&m,&n);
		xy  bom[m],
			man[n];
		int tou[m],now=0;
		for(int i=0;i<m;++i)
			scanf("%d%d%d",&bom[i].x,&bom[i].y,&bom[i].r);
		for(int i=0;i<n;++i)
			scanf("%d%d%d",&man[i].x,&man[i].y,&man[i].r),
			now |= 1<<i ;
		
		for(int i=0;i<m;++i)
		{			
			tou[i]=0;
			for(int j=0;j<n;++j)
				if(touch(bom[i].x-man[j].x, bom[i].y-man[j].y , bom[i].r+man[j].r))
					tou[i] |= 1<<j;
		}
		min=INT_MAX;
		dfs(tou,m-1,0,now);
		if(min==INT_MAX)
			puts("Impossible");
		else
			printf("%d\n",min);
	};
	return 0;
};
/*
3 
3 2 
11 1 1 
1 -1 1 
5 0 5 
10 0 1 
0 0 1 
2 2 
11 1 1 
1 -1 1 
10 0 1 
0 0 1 
1 2 
11 1 1 
10 0 1 
0 0 1
*/

#include<bits/stdc++.h>
#define M 100100
#define lld long long int 
std::vector<int> v [M];
int road [M],
	vis[M];
#define pii std::pair<int,int> 
#define mk std::make_pair
int dfs(int n)
{			
	std::queue< pii > q;
	
	q.push( mk(1,0) );
	vis[1] = 0;
	
	
	int ok=0;
	while(q.size())
	{
		pii p = q.front();
		q.pop();
		
		int now = p.first ,
			nth = (p.second + 1) % 2 ;
			
		for(int i:v[now])
			if(vis[i] == -1)
			{
				vis[i] = nth ;
				q.push( mk(i,nth) );	
			}
			else if( vis[i] ==  p.second )
					ok = 1;
						
	};	
	for(int i=1;i<=n;++i)
		if(vis[i] == -1)
			return 0;
	//puts("zxc");
	if(ok)
		return 1;
	
	int zero=0 , tru =0 ;
	for(int i=1;i<=n;++i)
		if(road[i] == 0)
			++zero;
		else if(road[i] == vis[i]+1)
			++tru;
			
	return (zero+tru == n) || (tru==0) ;
	
	
};

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",road+i);
			v[i] = std::vector<int>() ;
			vis[i] = -1;
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);			
		};
		
		if(dfs(n))
			puts("Paul Wang Bang Bang");
		else
			puts("Paul Wang Huai Huai");
		
				
	}
    return 0;
}

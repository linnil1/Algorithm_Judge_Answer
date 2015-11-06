#include<bits/stdc++.h>
//#include<algorithm>
#define ll long long 
#define yesT
#define M 50100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

struct box
{
	int pi;
	vi v;
	inline void clear()
	{
		pi=0;
		v=vi();
	}
 } vx[3][M],vy[3][M],vz[3][M];



int main()
{
	//std::ios::sync_with_stdio(false);
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
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		for(int j=0;j<3;++j)
		{		
			for(int i=1;i<=x;++i)
				vx[j][i].clear();
			for(int i=1;i<=y;++i)
				vy[j][i].clear();
			for(int i=1;i<=z;++i)
				vz[j][i].clear();
		};
		
		int n;
		ll sum=(ll)x*y*z;
		
		#define tuple std::pair<std::pair<int,int>,int>
		
		std::unordered_map< tuple  ,int> m;
		
		scanf("%d",&n);
		while(n--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			
			++m.[ std::tie(a,b,c)];
			
			if(c==0)
			{
				sum-=z;
				sum+=vx[1][a].pi;
				sum+=vy[0][b].pi;
				
				for(int i:vx[1][a].v)
					++m[std::tie(0,b,i)];
				for(int i:vy[0][b].v)
					++m[ std::tie(a,0,i) ];				
									
				++vx[2][a].pi;
				vx[2][a].v.pb(b);				
				++vy[2][b].pi;
				vy[2][b].v.pb(a);
			}
			if(b==0)
			{
				sum-=y;
				sum+=vx[2][a].pi;
				for(int i:vx[2][a].v)
					++m[std::tie(0,i,c)];
				sum+=vz[0][c].pi;	
				for(int i:vz[0][c].v)
					++m[std::tie(a,i,0)];
							
				++vx[1][a].pi;
				vx[1][a].v.pb(c);				
				++vz[1][c].pi;
				vz[1][c].v.pb(a);
			}
			if(a==0)
			{
				sum-=x;
				sum+=vy[2][b].pi;
				for(int i:vy[2][b].v)
					++m[std::tie(i,0,c)];
				sum+=vz[1][c].pi;	
				for(int i:vz[1][c].v)
					++m[std::tie(i,b,0)];			
				++vy[0][b].pi;
				vy[0][b].v.pb(c);
				++vz[0][c].pi;
				vz[0][c].v.pb(b);
			}
			for(pair<tuple<int,int,int>,int> i:m)
				if(i.second == 3)
					--sum;
			
		}
		printf("%lld\n",sum);
		
	};
	return 0;
};
/*
100
3 3 3
3
2 2 0
0 2 2
2 0 2

*/

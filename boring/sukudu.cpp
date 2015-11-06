#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define N 3
#define M N*N
#define MOD 1000000007
#define mp std::make_pair
#define pii std::pair<int,int>
#define pb push_back
#define qi std::queue<int>


int ok,map[M][M],r[M],c[M],bloc[N][N];

std::vector< pii > v;

void sukudu(int now)
{
	if(ok)
		return ;
	if(now == v.size())
	{
		ok=1;
		return ;
	}
	for(int t=0;t<M;++t)
	{
		int tmp = 1<<t , &x = v[now].first , &y = v[now].second;
		if( (r[x]&tmp) && (c[y]&tmp) && (bloc[x/N][y/N]& tmp) )
		{
			r[x] ^= tmp ;
			c[y] ^= tmp ;
			bloc[x/N][y/N] ^= tmp ;
			map[x][y] = t+1;
			sukudu(now+1);
			if(ok)
				return ;
			r[x] ^= tmp ;
			c[y] ^= tmp ;
			bloc[x/N][y/N] ^= tmp ;
		}
	}					
}


int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		ok =0;
		v.clear();
		std::fill(r,r+M,0777);
		std::fill(c,c+M,0777);
		std::fill((int *)bloc,(int *)bloc+M,0777);
		for(int i=0;i<M;++i)
			for(int j=0;j<M;++j)
			{
				scanf("%d",map[i]+j);
				if(!map[i][j])
					v.pb( mp(i,j) );
				else
				{
					int tmp = 1<< (map[i][j]-1);
					r[i]^=tmp;
					c[j]^=tmp;
					bloc[i/N][j/N]^=tmp;
				}
			};
		
		
		sukudu(0);
		if(ok)
			for(int i=0;i<M;++i,puts(""))
				for(int j=0;j<M;++j)
					printf("%d ",map[i][j]);
		else
			puts("no solution");
		
					
	};
	return 0;
};
/*
1
0 6 0 1 0 4 0 5 0
0 0 8 3 0 5 6 0 0
2 0 0 0 0 0 0 0 1
8 0 0 4 0 7 0 0 6
0 0 6 0 0 0 3 0 0
7 0 0 9 0 1 0 0 4
5 0 0 0 0 0 0 0 2
0 0 7 2 0 6 9 0 0
0 4 0 5 0 8 0 7 0

*/

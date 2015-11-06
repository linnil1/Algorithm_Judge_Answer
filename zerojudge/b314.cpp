#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 1010
#define MOD 1000000007

std::pair<int,int> p[M*M];
bool ans[M*M];
int map[M][M],n,m;

struct disjointset
{
	int s[M*M],n,group;
	void init(int _n)
	{
		group = n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	};
	
	int find(int a)
	{
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b)
	{
		if(find(a)!=find(b))
		{
			s[find(a)] = find(b);
			--group;
			return 1;
		}
		else
			return 0;
	}	
	
}s;

bool can(int x,int y)
{
	int st=s.find(0),e=s.find((n-1)*m);
	int oks=1,oke=1;
	for(int i=-1;i<=1;++i)
		for(int j=-1;j<=1;++j)
		{
			int tx = x + i,
				ty = y + j;
			if(0<=tx && 0<=ty && tx<n && ty < m )
			{
				if(s.find(tx*m+ty)==st)
					oks=0;
				else if(s.find(tx*m+ty)==e)
					oke=0;
			}
		}
	return oks || oke ;
}

void gounin(int x,int y)
{
	for(int i=-1;i<=1;++i)
		for(int j=-1;j<=1;++j)
		{
			int tx = x + i,
				ty = y + j;
			if(0<=tx && 0<=ty && tx<n && ty < m && map[tx][ty])
				s.unin(tx*m + ty , x*m+y);
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
	int t;
	while(~scanf("%d%d%d",&n,&m,&t))
	#endif	
	{
		n+=2;
		s.init(n*m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				map[i][j] = 0 ;
		
		for(int i=0,k=(n-1)*m;i<m;++i)
		{		
			map[0][i] = map[n-1][i] = 1; 		
			if(i)
				s.unin(i-1,i),s.unin(k+i-1,k+i);
		}
				
				
		for(int i=0,x,y;i<t;++i)
		{
			scanf("%d%d",&x,&y);
			++x;
			if(can(x,y))
			{
				map[x][y]=1;
				puts("<(_ _)>");
				gounin(x,y);
			}
			else
				puts(">_<");
		}
		
		
			
		
		
	};
	return 0;
};
/*
*/

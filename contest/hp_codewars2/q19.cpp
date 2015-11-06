#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

struct road
{
	int to,val;
};


std::vector<road> city[25];

void bfs(int s,int e)
{
	std::queue<int> q; 
	
	int cost[25];
	for(int i=0;i<25;++i)
		cost[i]= INT_MAX;
	cost[s]=0;	
	q.push(s);
	while(q.size())
	{
		int now=q.front();q.pop();
		for(int i=0;i<city[now].size();++i)
			if( cost[now]+city[now][i].val < cost[ city[now][i].to ] )
			{
				cost[ city[now][i].to ] = cost[now] + city[now][i].val ;
				q.push( city[now][i].to );
			}
	}
	printf("%d ",cost[e]);
	
	std::vector<int >v ;
	v.pb(e);
	int now = e;
	while(now!=s)
	{
		for(int i=0;i<city[now].size();++i)
			if (  cost[city[now][i].to] + city[now][i].val == cost[now] )
			{
				now = city[now][i].to;
				v.pb(now);
				break;
			}
	}
	for(int i=v.size()-1;i>=0;--i)
		printf("%c ",v[i]+'A');
	puts("");
	
	
}

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
		for(int i=0;i<25;++i)
			city[i].clear();
			
		for(int i=0;i<n;++i)
		{
			char c[5],b[5];
			int val;
			scanf("%s%s%d",c,b,&val);
			c[0]-='A';b[0]-='A';
			city[ c[0] ] .pb ( road{b[0],val});
			city[ b[0] ] .pb ( road{c[0],val});
		}
		char c[5],b[5];
		scanf("%s%s",c,b);
		int s = c[0]-'A',e=b[0]-'A';
		
		bfs(s,e);
		
		
	};
	return 0;
};
/*
9
A B 10
A C 7
A D 10
B C 3
B F 25
C D 5
C E 9
D E 8
D F 2
A F

5
A B 3
B C 7
C A 11
B D 6
B E 25
A E

7
A B 6
D A 7
D C 11
E D 8
C A 10
A E 6
B D 5
C E


*/

#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define VN 10000
#define VM 100000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
struct E
{
	int go,val;
	E(){};
	E(int _go,int _val):go(_go),val(_val){};
};

struct flow
{
	int n,nuse=0;
	E e[VM];
	vi v[VN];
	void init(int _n)
	{
		n = _n ; nuse=0;
		for(int i=0;i<n;++i)
			v[i] = vi();
	}
	void add(int a,int b,int val)
	{
		v[a].pb(nuse);e[nuse]=E(b,val);++nuse;
		v[b].pb(nuse);e[nuse]=E(a,  0);++nuse;
	}
	
	int dis[VN];
	int bfs()
	{		
		for(int i=1;i<n;++i)
			dis[i]=INT_MAX;
		dis[0]=0;
		qi q;
		q.push(0);
		while(q.size() && dis[n-1]==INT_MAX)
		{
			int now = q.front() ; q.pop();
			for(int i=0;i<v[now].size();++i)
			{
				E &ee = e[ v[now][i] ] ;
				if(ee.val &&   dis[ee.go] == INT_MAX )
				{
					dis[ee.go] = dis[now]+1;
					q.push(ee.go);
				}
				
			}
			/*for(int i=0;i<n;++i)
				printf("%d ",dis[i]);
			puts("");*/
			
		}
		return dis[n-1] !=	INT_MAX;
	};
	
	int ptr[VN];
	int go(int to,int val)
	{
		if(to == n-1)
			return val;
		for(int &i=ptr[to];i<v[to].size();++i)
		{
			E &ee =e[ v[to][i] ];
			if(ee.val && dis[to]+1==dis[ee.go] )
			{
				int plu = go(ee.go , std::min(val,ee.val) );
				if(plu)
				{
					ee.val-=plu;
					e[ v[to][i]^1 ].val +=plu;
					return plu;
				}
			}
			
		}
		return 0;
	}
	
	int maxflow()
	{
		int sum=0,tmp;
		while(bfs())
		{
			for(int i=0;i<n;++i)
				ptr[i]=0;
			while( (tmp=go(0,INT_MAX)) )
				sum+=tmp;
		};
		return sum;
	}
		
}f;

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int count,T;
	scanf("%d",&T);
	count = T;
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n,k;
		scanf("%d%d",&n,&k);
		
		f.init(n-1+k+2);
		for(int i=n;i<n+k;++i)
			f.add(i,n+k,1);
			
		int arr[k+1],time,t;		
		for(int i=0;i<n;++i)
		{
			for(int j=1;j<=k;++j)
				arr[j]=0;
			scanf("%d",&time);
			while(time--)
			{
				scanf("%d",&t);
				++arr[t];
			}
			if(i)
				for(int j=1;j<=k;++j)
					if(arr[j]>1)
						f.add(i,n+j-1,arr[j]-1);
					else if(arr[j] == 0 )
						f.add(n+j-1 , i , 1);
					else;
			else
				for(int j=1;j<=k;++j)
					f.add(i,n+j-1,arr[j]);
		}
		
		printf("Case #%d: %d\n",count-T,f.maxflow());
		
		
	};
	return 0;
};
/*
*/

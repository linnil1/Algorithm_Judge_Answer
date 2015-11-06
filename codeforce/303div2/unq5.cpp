#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string

struct xy
{
	int x,y,val,num;
};

bool operator <(xy a,xy b)
{
	return a.val>=b.val;
};

struct disjoint
{
	int g[M],n,group;
	void init(int a)
	{		
		n=a;
		group=n;
		for(int i=0;i<=n;++i)
			g[i]=i;
	}
	int find(int a)
	{
		return g[a]==a?a : g[a]= find(g[a]);
	}
	int unin(int a,int b)
	{
		if(find(a)==find(b))
			return 0;
		g[a]=g[b];
		--group;		
		return 1;
	}
	
	
}dj;



int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n,m;
	while(~scanf("%d%d",&n,&m))
	#endif	
	{
		xy arr[m];

		std::vector<xy> v[n];
		for(int i=0;i<m;++i)
		{
		
			scanf("%d%d%d",&arr[i].x,&arr[i].y,&arr[i].val);
			--arr[i].x;
			--arr[i].y;
			arr[i].num=i;
			v[arr[i].y].pb(arr[i]);
			
			std::swap(arr[i].x,arr[i].y);
			v[arr[i].y].pb(arr[i]);
		};	
		int s;
		scanf("%d",&s);
		--s;
		dj.init(n);
		xy pot[n];
		for(int i=0;i<=n;++i)
			pot[i].val=INT_MAX;
		pot[s].val=0;				
		
		std::priority_queue<xy> q;		
		q.push( xy{s,0,0,0} );
				
		vi ans;
		int sum=0;
		
		while(q.size())
		{
			//printf("%d ",dj.group);
			int nowxy=q.top().num,
				p = q.top().val,
				now = q.top().x;
			printf("%d\n",p);		
			q.pop();
			
			if(dj.find(now)!=dj.find(s))
			{
				ans.pb(nowxy);
				sum+=arr[nowxy].val;//printf("%d?",dj.group);
				dj.unin(now,s);//printf("%d!",dj.group);
			}
			else if(now!=s)
				continue;
			
			for(auto i:v[now])
				if(pot[now].val+i.val<pot[i.x].val)
				{
					pot[i.x]=i;
					pot[i.x].val+=pot[now].val;
										
					q.push( pot[i.x] );
				}		
		}
		
						
		std::sort(ans.begin(),ans.end());
		printf("%d\n",sum);
		for(int i=0;i<ans.size();++i)
			printf("%d ",ans[i]+1);
		puts("");
		
		
	};
	return 0;
};
/*
*/

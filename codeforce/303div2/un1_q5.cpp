#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 500100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string

struct road
{
	int from,go,num,val;
};
bool operator <(road a,road b)
{
	return a.val>b.val;
}
vi bfs (road* arr,int n,int m)
{
	std::vector<road> r[n];
	for(int i=0;i<m;++i)
	{
		r[ arr[i].from ].pb(arr[i]);
		std::swap(arr[i].from,arr[i].go);
		r[ arr[i].from ].pb(arr[i]);
	}
	
	int ver[n];
	for(int i=0;i<n;++i)
		ver[i]=INT_MAX;
	
	int s;
	scanf("%d",&s);
	--s;
	ver[s]=0;
	
	std::priority_queue<road> q;
	q.push( road{0,s,-1,0});
	vi ans;
	
	while(q.size())
	{
		
		road t= q.top();
		q.pop();
		int now=t.go;
		if(ver[now] == t.val && t.val)
			ans.pb(t.num);
		else if(ver[now] != t.val)
			continue;
		for(auto i:r[now])
			if(ver[now]+i.val <= ver[i.go])
			{
				ver[i.go] = ver[now]+i.val;
				q.push( road{i.from,i.go,i.num,ver[i.go]} );
			}		
		
	}
	
	/*for(int i:ans)
		printf("%d ",i);
	puts("!!");*/
	
	return ans;	
}

struct disjointset
{
	int s[M],n,group;
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

struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};

vi mintree(vi &v,road *arr,int n)
{
	std::vector<xy > vp;
	for(int i=0;i<v.size();++i)
		vp.pb(xy(arr[v[i]].val,v[i]));
	std::sort(vp.begin(),vp.end());
	s.init(n);
	vi ans;
	for(int i=0;s.group>1 && i<vp.size();++i)
		if(s.unin(arr[vp[i].y].from,arr[vp[i].y].go))
			ans.pb(vp[i].y);	
	return ans;
	
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
	int n,m;
	while(~scanf("%d%d",&n,&m))
	#endif	
	{
		road arr[m];		
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&arr[i].from,&arr[i].go,&arr[i].val);
			--arr[i].from;--arr[i].go;
			arr[i].num=i;
		}
		vi vans = bfs(arr,n,m);
		vi v= mintree(vans,arr,n);
		
		ll sum=0;
		for(int i=0;i<v.size();++i)
			sum+=arr[v[i]].val;
		printf("%I64d\n",sum);
		std::sort(v.begin(),v.end());
		for(int i=0;i<v.size();++i)
			printf("%d ",v[i]+1);
		puts("");
		
	};
	return 0;
};
/*
*/

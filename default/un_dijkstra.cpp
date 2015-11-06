
struct xy
{
	int fr,go,val;
};
struct dijkstra
{
	typedef std::pair<int,int> pii ;
	static const int MM = 100000;
	std::vector< pii > v[MM];	
	int ver[MM],use[MM];
	int n,m;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<n;++i)
			v[i] = std::vector< pii >();
	}
	void add(int x,int y,int val)
	{
		v[x].pb ( mp(y,val) );
		v[y].pb ( mp(x,val) );
	}
	void go(int s=0)
	{
		for(int i=0;i<n;++i)
			ver[i]=INT_MAX,use[i]=0;
		ver[s]=0;
		std::priority_queue< pii ,
		std::vector< pii > ,
		std::greater< pii > > q;
		q.push( mp(0,s) );
		while(q.size())
		{
			int now =q.top().sd;q.pop();
			if(use[now])continue;
			use[now]=1;
			for(auto &i:v[now])
				if(ver[i.ft] > ver[now]+i.sd)
				{
					ver[i.ft] = ver[now]+i.sd ;
					q.push( mp(ver[i.ft],i.ft) );
				}
		}		
	}	
}dij;

struct E{
	int go,val;
	E(){};
	E(int _go,int _val):go(_go),val(_val){};
};
struct flow{
	static const int VM = 10000,VN=10000;
	int n,nuse=0;
	E e[VM];
	VI v[VN];
	
	void init(int _n){
		n = _n ; nuse=0;
		for(int i=0;i<n;++i)
			v[i] = VI();
	}
	
	void add(int a,int b,int val){
		v[a].pb(nuse);e[nuse]=E(b,val);++nuse;
		v[b].pb(nuse);e[nuse]=E(a,  0);++nuse;
	}	
	
	int dis[VN];
	int bfs(){		
		for(int i=1;i<n;++i)
			dis[i]=INT_MAX;
		dis[0]=0;
		std::queue<int> q;
		q.push(0);
		while(q.size()){
			int now = q.front() ; q.pop();
			for(int i=0;i<v[now].size();++i){
				E &ee = e[ v[now][i] ] ;
				if(ee.val &&   dis[now]+1 < dis[ee.go] ){
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
	int go(int to,int val)	{
		if(to == n-1)
			return val;
		for(int &i=ptr[to];i<v[to].size();++i){
			E &ee =e[ v[to][i] ];
			if(ee.val && dis[to]+1==dis[ee.go] ){
				int plu = go(ee.go , std::min(val,ee.val) );
				if(plu){
					ee.val-=plu;
					e[ v[to][i]^1 ].val +=plu;
					return plu;
				}
			}
			
		}
		return 0;
	}	
	
	int maxflow(){
		int sum=0,tmp;
		while(bfs()){
			for(int i=0;i<n;++i)
				ptr[i]=0;
			while( (tmp=go(0,INT_MAX)) )
				sum+=tmp;
		};
		return sum;
	}		
}f;

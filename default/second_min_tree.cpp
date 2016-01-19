struct disjointset
{
	static const int MM=100100;
	int s[MM],n,group;
	
	void init(int _n){
		group = n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	};	
	inline int find(int a){
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b){
		if(find(a)!=find(b)){
			s[find(a)] = find(b);
			--group;
			return 1;
		}
		else
			return 0;
	}	
	
}disj;


struct road{
	int s,t,v,u;
	bool operator < (const road &a)const{
		return v <a.v;
	}
};
inline void roadin(int &,int &,int &);

struct second_tree{ 
	static const int MM=100100;
	std::vector< std::pair<int,int> > map[MM];

	int n;
	void init(int _n){
		n = _n;
		for(int i=0;i<n;++i)
				map[i]=std::vector< std::pair<int,int> >();
	}

	road r[MM*10];
	int m;

	void makemap(int _m){
		m = _m;
		for(int i=0;i<m;++i){
			roadin(r[i].s,r[i].t,r[i].v);
			r[i].u=0;
		}
		std::sort(r,r+m);
		for(int i=0;i<m;++i){
			map[r[i].s].pb(  std::make_pair(r[i].t,i) );
			map[r[i].t].pb(  std::make_pair(r[i].s,i) );
		}
	}

	int getmintree(){
		int sum=0;
		disj.init(n);
		for(int i=0;i<m && disj.group>1 ; ++i)
			if(disj.unin(r[i].s,r[i].t)){
				sum += r[i].v;
				r[i].u=1;
			}
		return sum;
	}

	int big[MM];
	void calbig(int now){
		for(int i=0;i<n;++i)
			big[i]=-1;
		std::queue<int> q;
		q.push(now);
		big[now]=0;
		while(q.size()){
			int now = q.front();q.pop();
			for(int i=0;i<map[now].size();++i){
				std::pair<int,int> &t = map[now][i];
				if(big[t.ft]<0 && r[t.sd].u){
					big[t.ft] = MAX(big[now],r[t.sd].v);
					q.push(t.ft);
				}
			}
		}
	}

	int getsectree(){
		int minc=getmintree(),min=INT_MAX;
		for(int i=0;i<n;++i){
			calbig(i);
			for(int j=0;j<map[i].size();++j)
				if(r[map[i][j].sd].u==0)
					min	= MIN(min,minc+r[map[i][j].sd].v-big[map[i][j].ft]);
		}
		return min;
	}
}sec;


//do it here
inline void roadin(int &s,int &t,int &v){
	scanf("%d%d%d",&s,&t,&v);
}
